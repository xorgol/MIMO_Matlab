# MIMO_Matlab
Made by the [Artsoundscapes Project](https://www.ub.edu/artsoundscapes/)

Converts MIMO acoustical measurements to their Impulse Responses. In development: calculate acoustical parameters.
This is specific to our particular pairing between sound source and microphone, and to the sine sweep employed.
Basic operation instructions: select the path containing your measurements when prompted, the results will be put in an 'output' subfolder.

For a brief explanation visit www.adrianofarina.it/MIMO

## Known issues
- Crashes if the recording is shorter than two sweeps plus their silence (but that is a failed recording anyway).
- The progressbar disappears and then reappears again.

## Wishful next steps
- Redo the UI as a single window application
- Compile functions, and in particular fd_conv, to C
- Process multiple folders in one go
