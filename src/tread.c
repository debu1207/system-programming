#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
#include <errno.h>

int main() {
	int fd, count = 10;
	ssize_t res;
	char *buf;
	buf = (char *)malloc(count + 1);

	if (!buf) {
		printf("Error on malloc(): %d\n", errno);
		exit(1);
	}
		
	fd = open("tempfile", O_RDWR | O_CREAT , 0755);
	if (fd < 0) {
		printf("Error on open(): %d\n", errno);
		exit(1);
	}

	res = read(fd, buf, count);
	buf[count] = '\0';

	printf("Buffer read: %s\n", buf);

	close(fd);
	free(buf);
	return 0;
}
