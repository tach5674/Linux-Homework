#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
  int fd1[2];
  pipe(fd1);
  int fd2[2];
  pipe(fd2);
  if (fork() == 0) {
    dup2(fd1[1], 1);
    close(fd1[0]);
    close(fd1[1]);
    execlp(argv[1], argv[1], NULL);
  }
  if (fork() == 0) {
    dup2(fd1[0], 0);
    dup2(fd2[1], 1);
    close(fd2[0]);
    close(fd2[1]);
    execlp(argv[2], argv[2], NULL);
    _exit(1);
  }
  if (fork() == 0) {
    dup2(fd2[0], 0);
    close(fd2[0]);
    close(fd2[1]);
    execvp(argv[3], argv + 3);
    _exit(1);
  }
  close(fd2[0]);
  close(fd2[1]);
  return 0;
}

