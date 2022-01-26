/*
 * Please compile with gcc -Wall helloworld_pthreads.c -lpthread
 */

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define NUM_THREADS	10

void *print_hello_world(void *tid)
{
   long threadid;
   threadid = (long)tid;
   printf("Hello World! Greetings from thread #%ld!\n", threadid);
   pthread_exit(NULL);
}

int main(int argc, char *argv[])
{
   pthread_t threads[NUM_THREADS];
   int status;
   long i;

   for(i=0; i<NUM_THREADS; i++){
     printf("Main here. Creating thread %ld\n", i);
     status = pthread_create(&threads[i], NULL, print_hello_world, (void *)i);
     if (status != 0){
       printf("ERROR; return code from pthread_create() is %d\n", status);
       exit(-1);
       }
     }
   pthread_exit(NULL);
}
