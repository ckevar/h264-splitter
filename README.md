# h264-splitter
With this utility you can split a raw h264 file into chunk files with one NAL unit each.

## Getting Started
Once this repository is cloned, type the following on terminal to create the executable h264Splitter3 and h264Splitter4 

```
make all
```
* **h264Splitter3** for *001* header starter NAL unit
* **h264Splitter4** for *0001* header starter NAL unit

### Prerequisites

This has been coded to run under Linux. (tested on pop-os!)

#### What Separator does my file have?
##### on Linux
I recommend you to use a binary reader such as *xxd*. Open a terminal and type the following
```
xxd <you_h264_file> | head -n 3
```
this will give you a result like this:
```
00000000: 0000 0001 6742 c01f da03 204d f961 0000  ....gB.... M.a..
00000010: 0300 0100 0003 003c 8f18 32a0 0000 0001  .......<..2.....
00000020: 68ce 32c8 0000 0106 05ff ff62 dc45 e9bd  h.2........b.E..
```
The important part is the first line
```
00000000: 0000 0001 6742 c01f da03 204d f961 0000  ....gB.... M.a..
```
we can conclude that this file uses a **0001** header starter, because it has *0000 0001* at the beginning. On the other hand, if your file has the following at the first line:
```
00000000: 0000 0167 42c0 1fda 0320 4df9 61000003  ...gB.... M.a...
```
your file has a **001** header starter.
##### on Mc or Windows
I recomend you to use a binary reader and check the first line

### What if my file is mp4?

Remember that mp4 is a container and not a codec, so you have to use ffmpeg. Try this:
```
ffmpeg -i <your_file_name>.mp4 -an -vcodec libx264 -crf 23 <your_output_file_name>.h264
```
## Running the tests
For running the splitter
```
./h264Splitter4 <your_h264_file>
```
this will generate one file per each NAL unit contained in your h264 file, it will start at 0 until the last NAL unit, like this:

```
<your_h264_file>.0000
<your_h264_file>.0001
<your_h264_file>.0003
.
.
.
<your_h264_file>.<last_NAL_unit>
```
Remember that NAL units can be interpreted as "frames"

## Acknowledgment
* [Exploring H.264. Part 2: H.264 Bitstream format](http://gentlelogic.blogspot.com/2011/11/exploring-h264-part-2-h264-bitstream.html)

* [Introduction to H.264: (1) NAL Unit](https://yumichan.net/video-processing/video-compression/introduction-to-h264-nal-unit/)