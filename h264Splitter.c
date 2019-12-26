#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>

#ifdef STARTER264NAL4
int STARTER264NAL = 4;
unsigned char starter[] = {0, 0, 0, 1};
#else
int STARTER264NAL = 3;
unsigned char starter[] = {0, 0, 1};
#endif

int main(int argc, const char *argv[]) {
	
	int f = open(argv[1], O_RDONLY);
	char fileName[50];
	unsigned MAX_BUFFER_SIZE = 256;
	unsigned char data[MAX_BUFFER_SIZE];
	unsigned char tmp[MAX_BUFFER_SIZE];
	unsigned char *head;
	unsigned char *tail;
	unsigned char *DATA_TAIL;

	memset(data, 0, MAX_BUFFER_SIZE);

	int sw = 0;
	long int nalIdx = 0;
	int nalUnit = -1;

	DATA_TAIL = data + MAX_BUFFER_SIZE - 1;
	head = data;

	while (1) {
		int len = read(f, head, DATA_TAIL - head + 1);

		if (len <= 0) {
			close(nalUnit);
			break;
		}

		tail = data;
		head -= STARTER264NAL - 1;
		sw = 0;

		while(head < DATA_TAIL - (STARTER264NAL - 2)) {
			if(memcmp(head, starter, STARTER264NAL) == 0) {
				sw = 1;
				if (nalUnit > 0) {
					write(nalUnit, tail, head - tail);
					close(nalUnit);
				}
				tail = head;
				printf("New NAL unit created %ld\n", nalIdx);
				sprintf(fileName, "%s.%04ld",argv[1], nalIdx);
				nalUnit = open(fileName, O_CREAT | O_WRONLY, 0666);
				nalIdx++;
			}
			head++;
		}


		if (sw == 0) {
			write(nalUnit, tail, head - tail);
			memcpy(tmp, head, DATA_TAIL - head + 1);
			memcpy(data, tmp, DATA_TAIL - head + 1);
			head = data + (DATA_TAIL - head + 1);
		}
		else {
			memcpy(tmp, tail, DATA_TAIL - tail + 1);
			memcpy(data, tmp, DATA_TAIL - tail + 1);
			head = data + (DATA_TAIL - tail + 1);
		}
	}

	write(nalUnit, data, (DATA_TAIL - data));
	close(nalUnit);
	close(f);
	return 0;
}
