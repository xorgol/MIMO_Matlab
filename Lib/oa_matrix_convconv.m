%*************************************************************************************************
% matrix_conv.m                                                              Lorenzo Chiesi 2013 *
%                                                                                                *
%                                                                                                *
%*************************************************************************************************
%
% BFMimoIR = matrix_convconv(SpkBF,MimoIR,MicBF);
%
% SpkBF IR matrix of the speaker beamformer with dimension [VSpk x RSpk x NSpk]
% MimoIR Input signal/ir matrix with dimension [RSpk x RMic xNir]
% MicBF Input signal/ir matrix with dimension [RMic x VMic x NMic]
%
% BFMimoIR is the output beamformed mimo ir with size 
% [VSpk x RSpk x NSpk] * [RSpk x RMic x Nir] * [RMic x VMic x NMic] => [VSpk x VMic x Nir+NMic+NSpk-2]


function BFMimoIR = matrix_convconv(SpkBF,MimoIR,MicBF)

    [VSpk,RSpk,NSpk] = size(SpkBF);
    [RSpk1,RMic,Nir] = size(MimoIR);
    [RMic1,VMic,NMic] = size(MicBF);
    
    if ((RSpk~=RSpk1)||(RMic~=RMic1)) 
        display('ERROR matrix_conv: Dimension mismatch!')
        BFMimoIR = [];
        return
    end
    
    %Compute the dimension of processing chunk and FFT
    NChunk = 2^ceil(log2(NSpk+NMic));
    Nfft = 2^ceil(log2(NSpk+NMic+NChunk));
    
    %Compute dimension of output and preallocate memory
    Nout = Nir+NSpk+NMic-2;
    B = ceil(Nout/NChunk);
    BFMimoIR = zeros(VSpk,VMic,B*NChunk,class(MimoIR)); 

    
    %Compute FFT of beamformer
    fdSpkBF = fft(SpkBF,Nfft,3);
    fdSpkBF = fdSpkBF(:,:,1:Nfft/2+1);
    fdMicBF = fft(MicBF,Nfft,3);
    fdMicBF = fdMicBF(:,:,1:Nfft/2+1);
    
        
    %Preallocate space for fd matrix product
    fdBFMimoIR = zeros(VSpk,VMic,Nfft,class(MimoIR)); 
    
    %Ciclo sui buffer
    n = 1;
    for b = 1:1:B-1
        
        fprintf('Progress: %d%%\n',round(b/B*100));
        
        %Compute FFT of input data chunck
        nf = min(n+NChunk-1,Nir);
        fdMimoIR = fft(MimoIR(:,:,n:nf),Nfft,3);
        fdMimoIR = fdMimoIR(:,:,1:Nfft/2+1);
        
        %Copmpute matrix product
        for k = 1:(Nfft/2+1)
            fdBFMimoIR(:,:,k) = fdSpkBF(:,:,k) * fdMimoIR(:,:,k) * fdMicBF(:,:,k);
        end
        for k = Nfft/2+2:Nfft
            fdBFMimoIR(:,:,k) = conj(fdBFMimoIR(:,:,Nfft-k+2));
        end
        
        %trasform result to time domain and add to output data
        BFMimoIR(:,:,n:n+Nfft-1) = BFMimoIR(:,:,n:n+Nfft-1) + ifft(fdBFMimoIR,Nfft,3);   
        
        %Point to the next data chunk
        n = n + NChunk;
        
    end
    
    
    BFMimoIR = BFMimoIR(:,:,1:Nout);
    
    
end




