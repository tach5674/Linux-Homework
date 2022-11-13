#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
  if (argc < 5) {
    char err[20] = "Not enough args\n";
    write(2, err, sizeof(err));
    _exit(1);
  }

  int fd[2];
  if (pipe(fd) == -1) {
    perror(NULL);
    _exit(2);
  }

  if (fork() == 0) {
    int fd1 = open(argv[2], O_RDONLY);
    if (fd1 == -1) {
      perror(argv[2]);
      _exit(2);
    }
    dup2(fd1, 0);
    dup2(fd[1], 1);
    close(fd1);
    close(fd[1]);
    execlp(argv[1], argv[1], NULL);
  }

  if (fork() == 0) {
    int fd2 = open(argv[4], O_WRONLY | O_TRUNC | O_CREAT, 0600);
    if (fd2 == -1) {
      perror(argv[2]);
      _exit(2);
    }
    dup2(fd2, 1);
    dup2(fd[0], 0);
    close(fd2);
    close(fd[0]);
    execlp(argv[3], argv[3], NULL);
  }

  return 0;
}