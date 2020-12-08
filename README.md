# MIMO_Matlab
Made by the [Artsoundscapes Project](https://www.ub.edu/artsoundscapes/)

Converts MIMO acoustical measurements to their Impulse Responses and calculates the ISO3382 acoustical parameters using Angelo Farina's [AcouPar](http://www.angelofarina.it/Public/AcouPar).
This is specific to our particular pairing between sound source and microphone, and to the sine sweep employed.
Basic operation instructions: select the path containing your measurements when prompted, the results will be put in an 'output' subfolder.
In order to just calculate the acoustical parameters run justPars.m, pointing it to the folder containing your W_WY impulse responses.
If you have binaural IRs you can just change to AcouPar BIN instead of AcouPar PU.

For a brief explanation visit www.adrianofarina.it/MIMO

## Known issues
- Crashes if the recording is shorter than two sweeps plus their silence (but that is a failed recording anyway).
- The progressbar disappears and then reappears again.

## Wishful next steps
- Redo the UI as a single window application
- Compile functions, and in particular fd_conv, to C
- Process multiple folders in one go

## Adapting to different hardware
If you want to set up a MIMO system with a different Ambisonics microphone, you can just adjust the number of microphone channels in the script, and load an appropriate filter matrix [from here](http://pcfarina.eng.unipr.it/Public/Xvolver/Filter-Matrices/Aformat-2-Bformat/)
