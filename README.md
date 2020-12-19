# MIMO_Matlab
Made by Adriano Farina for the [Artsoundscapes Project](https://www.ub.edu/artsoundscapes/)

Converts MIMO acoustical measurements to their Impulse Responses and calculates the ISO3382 acoustical parameters using Angelo Farina's [AcouPar](http://www.angelofarina.it/Public/AcouPar).
This is specific to our particular pairing between sound source and microphone, and to the sine sweep employed.
Basic operation instructions: select the path containing your measurements when prompted, the results will be put in an 'output' subfolder.
In order to just calculate the acoustical parameters run justPars.m, pointing it to the folder containing your W_WY impulse responses.
If you have binaural IRs you can just change to AcouPar BIN instead of AcouPar PU.

For a brief explanation visit www.adrianofarina.it/MIMO

## How to use


The assumption is that you have a large folder containing dozens of Impulse Response measurements, divided in date and site subfolders. When you launch the script it will prompt you for a folder path, and it will take as input every .w64 file in the specified folder and in all its subfolders. In each folder where a .w64 file is found, it will create an output folder, in which it will create the following output files:

- W_WY
- STI (Signal, Noise, IR)
- MIMOIR
- 1AMBI_3AMBI
- 1AMBI_1AMBI

To understand what they are, please refer to the [explanation page](https://www.adrianofarina.it/MIMO/script.html).

## Known issues
- The progressbar disappears and then reappears again.
- Only works on Windows, due to the progressbar library and to AcouPar
- Problematic files are stored as a long string full of repetitions

## Wishful next steps
- Redo the UI as a single window application
- Compile functions, and in particular fd_conv, to C
- Make available on Mac and Linux
- Rename the acoustical parameters output file to the provided folder name

## Adapting to different hardware
If you want to set up a MIMO system with a different Ambisonics microphone, you can just adjust the number of microphone channels in the script, and load an appropriate filter matrix [from here](http://pcfarina.eng.unipr.it/Public/Xvolver/Filter-Matrices/Aformat-2-Bformat/)
However, you will also need a beamforming matrix for you specific loudspeaker array.
