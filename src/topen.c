#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>

int main() {
	int fd;
	
	fd = open("tempfile", O_RDWR | O_CREAT, 0755);

	if (fd < 0) {
		printf("Error: %d\n", errno);
	}

	close(fd);

	return 0;
}
