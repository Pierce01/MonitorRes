# MonitorRes
Simple monitor controller that I use to change my monitor resolution from the command line!

### Displaying supported resolutions 
Usage: `./exe`
### Changing Resolutions
Usage: `./exe [x] [y]` (`./exe 1080 920`)\
Entering `1` will keep the changed resolution, and anything else to revert the most recent change.

## Building
```
mkdir build
cd build/
cmake ..
cmake --build . --config Release
```