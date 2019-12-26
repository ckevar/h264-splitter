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
#### For 001 header starters
comment line 6 and uncomment line 7. Currently it's like this: 

```
int STARTER264NAL = 4;
// int STARTER264NAL = 3;
```
it should be like this
```
// int STARTER264NAL = 4;
int STARTER264NAL = 3;
```
Also modify the line 17, instead of this:

```
unsigned char starter[] = {0, 0, 0, 1};
```
it should be this:
```
unsigned char starter[] = {0, 0, 1};
```
##### Notes: I'm still working in automatize this section.
#### What Separator does my file has it?
##### on Linux
For that,I recomend you to use a binary reader such as xxd. In terminal type the following
```
xxd <you_h264_file> | head
```
this will give you the following result
```
00000000: 0000 0001 6742 c01f da03 204d f961 0000  ....gB.... M.a..
00000010: 0300 0100 0003 003c 8f18 32a0 0000 0001  .......<..2.....
00000020: 68ce 32c8 0000 0106 05ff ff62 dc45 e9bd  h.2........b.E..
```
Observing the first line,
```
00000000: 0000 0001 6742 c01f da03 204d f961 0000  ....gB.... M.a..
```
we can conclude that that file is a **0001** header because it has *0000 0001*. On the other hand if your file has the following at the first line:
```
00000000: 0000 0167 42c0 1fda 0320 4df9 61000003  ...gB.... M.a...
```
your file has a **001** header starters

## Running the tests
For running the splitter
```
./h264Splitter <your_h264_file>
```
this will generate one file per each NAL unit contained in your h264 file, from 0 until the last NAL unit, like this:

```
<your_h264_file>.0000
<your_h264_file>.0001
<your_h264_file>.0003
.
.
.
<your_h264_file>.<last_frame>
```
Remember that NAL units can be interpreted as "frames"
