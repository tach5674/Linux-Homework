#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>

int n;

void sighandler(int sig) {
  --n;
  printf("\n");
}

int main(int argc, char *argv[]) {
  if (argc < 2) {
    char buff[20] = "Not enough args\n";
    write(2, buff, sizeof(buff));
    _exit(1);
  }
  sscanf(argv[1], "%d", &n);
  if (n < 0) {
    char buff[20] = "Negative number\n";
    write(2, buff, sizeof(buff));
    _exit(1);
  }
  signal(SIGINT, sighandler);
  while (1) {
    printf("%d signals ramining\n", n);
    sleep(2);
    if (n < 0)
      break;
  }

  return 0;
}