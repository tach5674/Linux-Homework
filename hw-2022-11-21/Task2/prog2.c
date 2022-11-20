#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>

int main(void){
  int childpid;
  if((childpid = fork()) == 0){
    execl("prog1", "prog1", NULL);
  }
  int n;
  scanf("%d", &n);
  kill(childpid, n);
  int status;
  wait(&status);
  if (WIFSIGNALED(status)) {
    printf("Child terminated by signal %d\n", WTERMSIG(status));
  }
  return 0;
}
