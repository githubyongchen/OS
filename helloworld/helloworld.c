#include <stdio.h>
#include <stdlib.h>

int main()
{
  printf("Hello from process %d, \
	my parent process is: %d\n" , \
	getpid(), getppid());
  printf("GoodBye from process %d\n", getpid());
  exit(0);
}
