%*************************************************************************************************
% matrix_conv.m                                                              Lorenzo Chiesi 2013 *
%                                                                                                *
%                                                                                                *
%*************************************************************************************************
%
% C = matrix_conv(A,B);
%
% A Input signal/ir matrix with dimension [ra x ca x Na]
% B Input signal/ir matrix with dimension [rb x cb x Nb]
% !! A and B MUST have ca = rb !!
%
% C Result signal/ir convolution matrix with dimension [ra x cb x Na+Nb-1]

function C = matrix_conv(A,B) %#codegen

    [ra,ca,Na] = size(A);
    [rb,cb,Nb] = size(B);
    Nc = Na+Nb-1;
    NcR2 = 2^ceil(log2(Nc));
    
    if (ca~=rb) 
        display('ERROR matrix_conv: Dimension mismatch! ( cols(A) must be equal to rows(B) )')
        C = [];
        return
    end



    %Trasformazione nel dominio della frequenza dei segnali di ingresso

    display(sprintf('\n\t- Transforming to frequency domain...'))

    fdA = fft(A,NcR2,3);
    clear A
    fdA = fdA(:,:,1:NcR2/2+1);
    
    fdB = fft(B,NcR2,3);
    clear B
    fdB = fdB(:,:,1:NcR2/2+1);

    %Moltiplicazione matriciale nel dominio della frequenza

    fprintf('\n\t- Matrix multiplication...')

    completed = 0;
    old_completed = 0;
    %fdC = zeros(ra,cb,NcR2/2+1); 
    fdC = zeros(ra,cb,NcR2,class(fdA)); 
    for k = 1:(NcR2/2+1)
        fdC(:,:,k) = fdA(:,:,k) * fdB(:,:,k);
        
        completed = round(k/NcR2*100);
        if completed~=old_completed
            old_completed = completed;
            fprintf('\r\t- Matrix multiplication: %d',completed)
        end
        
    end
    
    clear fdA
    clear fdB

    %fdC = cat(3,fdC,zeros(ra,cb,NcR2/2-1));
    
    for k = NcR2/2+2:NcR2
        fdC(:,:,k) = conj(fdC(:,:,NcR2-k+2));
        
        completed = round(k/NcR2*100);
        if completed~=old_completed
            old_completed = completed;
            fprintf('\r\t- Matrix multiplication: %d',completed)
        end
        
    end
 

    %Antitrasformazione nel dominio del tempo

    display(sprintf('\n\t- Transforming back to time domain...'))

    C = ifft(fdC,NcR2,3);        
    clear fdC
    C = C(:,:,1:Nc);
    
end



