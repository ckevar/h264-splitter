CFLAGS = -Wall -Werror

h264Splitter: h264Splitter.c
	gcc $@.c $(CFLAGS) -o $@
