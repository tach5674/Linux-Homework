#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>

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
  int length = strlen(argv[1]);
  for(int i = 0; i < length; ++i){
    if(!(argv[1][i] >= '0' && argv[1][i] <= '9')){
      char buff[20] = "Invalid arguments\n";
      write(2, buff, sizeof(buff));
      _exit(1);
    }
  }
  sscanf(argv[1], "%d", &n);
  
  signal(SIGINT, sighandler);
  while (n >= 0) {
    printf("%d signals ramining\n", n);
    sleep(2);
  }

  return 0;
}
