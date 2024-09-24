#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

int main() {
	int fd, cnt = 10;
	ssize_t r;
	off_t res, offset = 5;
	char *buf;

	buf = (char *)malloc(cnt + 1);

	fd = open("tempfile", O_RDWR | O_CREAT, 0755);
	if (fd < 0) {
		printf("Error: %d\n", errno);
		exit(1);
	}
	// Read from beginning of the file
	r = read(fd, buf, cnt);
	buf[cnt] = '\0';
	printf("Buffer read: %s\n", buf);

	res = lseek(fd, offset, SEEK_SET);
	if (res < 0) {
		printf("Error: %d\n", errno);
		exit(1);
	}
	// Read after seek 5 character
	r = read(fd, buf, cnt);
	buf[cnt]='\0';
	printf("Buffer read after seek: %s\n", buf);

	res = lseek(fd, offset, SEEK_CUR);
        if (res < 0) {
                printf("Error: %d\n", errno);
                exit(1);
        }
        // Read after seek 5 character
        r = read(fd, buf, cnt);
        buf[cnt]='\0';
        printf("Buffer read after seek: %s\n", buf);

	close(fd);
	free(buf);

	return 0;
}
