#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

int main(int args, char *argv[]) {
  srand(time(NULL));
  int fd;
  fd = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0600);
  int n, m, k;
  sscanf(argv[1], "%d", &n);
  sscanf(argv[2], "%d", &m);
  sscanf(argv[3], "%d", &k);
  
  write(fd, &n, sizeof(n));
  
  int buff;
  for (int i = 0; i < n; ++i) {
    buff = rand() % (m + k + 1) - m;
    write(fd, &buff, sizeof(buff));
  }
  return 0;
}
