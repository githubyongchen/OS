#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#define FILESZ	(2 * 1024 * 1024) /* 2MB */

int main(int argc, char **argv) {
  char char_arr[4] = {'A', 'G', 'C', 'T'};
  char buff[4];
  int i, j;
  int fd;
  int r;

  if (argc != 2) {
    printf("Usage: %s <output file name>\n", argv[0]);
    exit(1);
  }

  fd = open(argv[1], O_CREAT | O_RDWR | O_TRUNC);
  if (fd == -1) {
    printf("Open/create %s error.\n", argv[1]);
    exit(-1);
  }

  for (i = 0; i < FILESZ / 4; i++) {  
    for (j = 0; j < 4; j++) {
      r = rand() % 4;
      buff[j] = char_arr[r];
    }
    write(fd, buff, 4); 
  }

  close(fd);
  exit(0);
} 
