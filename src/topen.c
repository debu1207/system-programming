#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>

int main() {
	int fd;
	// Try to open a fd of file tempfile. If doesn't exist, create the file.
	fd = open("tempfile", O_RDWR | O_CREAT, 0755);

	// Error handling. Always check the return value of syscalls.
	if (fd < 0) {
		printf("Error: %d\n", errno);
		exit(1);
	}

	// Essential to always close the fd after using.
	close(fd);

	return 0;
}
