CFLAGS = -Wall 
#-Werror

h264Splitter4: h264Splitter.c
	gcc $? $(CFLAGS) -o $@ -DSTARTER264NAL4

h264Splitter3: h264Splitter.c
	gcc $? $(CFLAGS) -o $@

all: h264Splitter3 h264Splitter4 
