#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include "proc_creation.h"

int main(int argc, char **argv) 
{
	pid_t my_pid;
	pid_t new_pid;

	my_pid = getpid();

	printf("Hello from Process %d; ", (int) my_pid);
	fflush(NULL);

	new_pid = fork(); /* Create a new process */
	if (new_pid == 0) { /* Child process */
		printf("Hello from Process %d; ", (int) getpid());
		printf("my Parent Process is %d\n", (int) getppid());
		fflush(NULL);
	} else { /* Parent process */
		printf("I created a new Process with PID %d\n", (int) new_pid);
		fflush(NULL);
		wait(NULL);
	}

	exit(0);
}

void hello_world() 
{
	printf("Hello from Process %d; ", (int) getpid());
	printf("my Parent Process is %d\n", (int) getppid());
	fflush(NULL);
}
