#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>

#define MAX_THREADS 16
#define POINTS	2000000000

void *compute_pi(void *);

int num_threads;

int main(int argc, char **argv)
{
	int i;
	int hits[MAX_THREADS];
	int total_hits = 0;

	pthread_t p_threads[MAX_THREADS];
	pthread_attr_t attr;
	pthread_attr_init(&attr);

	if (argc != 2) {
		printf("Usage: %s <number of threads>\n", argv[0]);
		printf("Using a default number of threads: %d\n", MAX_THREADS);
		num_threads = MAX_THREADS;
	} else {
		num_threads = atoi(argv[1]);
		if (!num_threads || num_threads > MAX_THREADS) {
			printf("Incorrect number of threads provided\n");
			printf("Using a default number of threads: %d\n", MAX_THREADS);
			num_threads = MAX_THREADS;
		}
	}

	for (i = 0; i < num_threads; i++) {
		hits[i] = i;
		pthread_create(&p_threads[i], &attr, compute_pi, (void *)&hits[i]);
	}
	for (i = 0; i < num_threads; i++) {
		pthread_join(p_threads[i], NULL);
		total_hits += hits[i];
	}

	printf("total hits: %d\n", total_hits);
	printf("total points: %d\n", POINTS);

	printf("pi is estimated as: %f\n", (double)total_hits / (double)POINTS * 4);

	exit(0);
}

void *compute_pi(void *s)
{
	unsigned int seed, i, *hit_pointer;
	double rand_no_x, rand_no_y;
	int local_hits;
	int sample_points_per_thread = POINTS / num_threads;

	hit_pointer = (unsigned int *)s;
	seed = *hit_pointer;
	local_hits = 0;
	for (i = 0; i < sample_points_per_thread; i++) {
		rand_no_x = (double)(rand_r(&seed)) / (double)(RAND_MAX);
		rand_no_y = (double)(rand_r(&seed)) / (double)(RAND_MAX);
		//printf("rand_no_x: %f, rand_no_y: %f\n", rand_no_x, rand_no_y);
		if (rand_no_x * rand_no_x + rand_no_y * rand_no_y <= 1.0)
			local_hits++;
		seed *= i;
	}
	*hit_pointer = local_hits;
	pthread_exit(0);
}
