#include <stdio.h>
#include <pthread.h>

#define NTHREADS 10

void *func(void *args) {
	int *val = (int *)args;
	printf("Thread %d running.\n", *val);
}

int main() {
	pthread_t thread_id[NTHREADS];
	int i, j;
	for (i = 0; i < NTHREADS; i++)
		pthread_create(&thread_id[i], NULL, func, &i);

	for (j = 0; j < NTHREADS; j++)
		pthread_join(thread_id[j], NULL);

	return 0;

}	

