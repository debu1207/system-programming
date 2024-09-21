#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>

int main() {
	printf("Start system programming\n");

	if (write(STDOUT_FILENO, "write syscall!\n", strlen("write syscall!\n")) < 0) {
		printf("Error: %d\n", errno);
		exit(1);
	}

	return 0;
}
