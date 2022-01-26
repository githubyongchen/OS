#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
	int i=0, pid;
	char input[50];
	char* arguments[10];
	while (1) {
		printf("Console> ");
		gets(input);
		if (strcmp(input, "quit") == 0)
			break;
		arguments[0] = strtok(input, " ");
		i = 0;
		while (arguments[i] != NULL) {
		    printf("argument[%d] = %s\n", i, arguments[i]);
		    i++;
		    arguments[i] = strtok(NULL, " ");
		}
		/*
		i = 0 ;
		while ( (arguments[i++] = strtok(NULL, " ")) !=NULL ) {};
		arguments[i] = NULL ;
		*/
		pid = fork();
		if (pid == 0) {
			if (execvp(arguments[0] , arguments) < 0) {
			    printf ("'%s': command not found\n", arguments[0]);
			}
			/*printf("Hello from process: %d", getpid());
			if (execle("/usr/bin/ls", "ls", "-al", (char *)0) < 0) {
			    printf("execle failed");
			}*/
			exit(0);
		} else {
			wait(NULL);
		}
	}
}
