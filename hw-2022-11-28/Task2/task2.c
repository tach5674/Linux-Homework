#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>

int n = 0;

void sigpipe_handler(int sig) {
  printf("Broken pipe!\n");
  n = 1;
}

int main(void){
  signal(SIGPIPE, sigpipe_handler);

  int fd[2];
  pipe(fd);

  if(fork() == 0){
    char str[5];
    read(fd[0], str, sizeof(str));
    write(1, str, sizeof(str));
    close(fd[0]);
    close(fd[1]);
    _exit(0);
  }

  char str[] = "Hello World";
  while(n == 0){
    write(fd[1], str, sizeof(str));
  }
  _exit(1);
}
