#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
  if (argc < 2) {
    char err[20] = "No args";
    write(2, err, sizeof(err));
    _exit(1);
  }
  char arr[1024];
  char *pr;
  char *input;
  char *args[sizeof(arr) / 2];

  int fd1 = open(argv[1], O_RDONLY);
  if (fd1 == -1) {
    perror(NULL);
    _exit(2);
  }
  int n = read(fd1, arr, sizeof(arr));

  int k = 0;
  int m = 1;
  int t;
  for (int i = 0; i <= n; ++i) {
    if (arr[i] == ' ' && k == 0) {
      arr[i] = '\0';
      pr = arr;
      ++k;
      t = i + 1;
      continue;
    }
    if (arr[i] == ' ' && k == 1) {
      arr[i] = '\0';
      input = arr + t;
      ++k;
      t = i + 1;
      continue;
    }
    if (arr[i] == ' ' || arr[i] == '\n') {
      arr[i] = '\0';
      args[m++] = arr + t;
      t = i + 1;
    }
  }
  args[0] = pr;
  args[m] = NULL;
  dup2(fd1, 0);
  lseek(fd1, SEEK_SET, 0);
  close(fd1);
  execvp(pr, args);

  return 0;
}