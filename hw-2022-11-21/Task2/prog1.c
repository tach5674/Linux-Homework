#include <stdio.h>
#include <unistd.h>

int main(void) {
  int pid = getpid();
  printf("%d\n", pid);
  while (1) {
  }
  return 0;
}
