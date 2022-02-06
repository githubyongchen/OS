#include <stdio.h>
#include <pthread.h>
#define MAX 100			/* how many numbers to produce */

pthread_mutex_t	the_mutex;
pthread_cond_t	condc, condp;	/* used for signaling */
int buffer = 0;	/* buffer used between producer and consumer */

void *producer(void *ptr)  /* produce data */
{				
	int i; 
	for (i = 1; i <= MAX; i++) {
		pthread_mutex_lock(&the_mutex);	/* get exclusive access to buffer */
		while (buffer != 0) {
			pthread_cond_wait(&condp, &the_mutex);
		}
		buffer = i;	/* put item in buffer */
		printf("producer put %d to buffer\n", buffer);
		pthread_cond_signal(&condc);	/* wakeup consumer */
		pthread_mutex_unlock(&the_mutex);	/* release access to buffer */
	}
	pthread_exit(0);
}


void *consumer(void *ptr) /* consume data */
{				
	int i;
	for (i = 1; i <= MAX; i++) {
		pthread_mutex_lock(&the_mutex);	/* get exclusive access to buffer */
		while (buffer == 0) {
			pthread_cond_wait(&condc, &the_mutex);	/* wakeupproducer */
		}
		printf("consumer take %d out of buffer, ", buffer);
		buffer = 0;
		printf("and set the buffer to %d\n", buffer);
		pthread_cond_signal(&condp);
		pthread_mutex_unlock(&the_mutex);	/* release access to buffer */
	}
	pthread_exit(0);
}


int main(int argc, char **argv)
{
	pthread_t pro, con;
	pthread_mutex_init(&the_mutex, NULL);
	pthread_cond_init(&condc, NULL);
	pthread_cond_init(&condp, NULL);
	pthread_create(&con, NULL, consumer, NULL);
	pthread_create(&pro, NULL, producer, NULL);
	pthread_join(pro, NULL);
	pthread_join(con, NULL);
	pthread_cond_destroy(&condc);
	pthread_cond_destroy(&condp);
	pthread_mutex_destroy(&the_mutex);
    return 0;
}