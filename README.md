# h264-splitter
An h264 file is composed by several [NAL units](http://gentlelogic.blogspot.com/2011/11/exploring-h264-part-2-h264-bitstream.html), and with this utility you can split that file in independent file units.

## Getting Started
Once this repository is cloned, type the following on terminal to create the executable h264Splitter

```
make
```

### Prerequisites

This has been developed to run under Linux.

Also consider, this will split h264 files with a starter 0001.
#### For 0001 header starters
Modify in line 12, instead of this:

```
unsigned char starter[] = {0, 0, 0, 1};
```
should be this
```
unsigned char starter[] = {0, 0, 1};
```
Also modify the line 39, instead of this:

```
if(memcmp(head, starter, 4) == 0) {
```
## Running the tests
This has bee developed to split 
```

```
