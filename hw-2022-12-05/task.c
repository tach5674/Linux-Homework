#include <stdio.h>
#include <pthread.h>

void* func(void* n){
  printf("%d\n", *(int *)n);
}

int main(void) {
  pthread_t t1, t2, t3, t4;
  int args[4] = {0, 1, 2, 3};
  pthread_create(&t1, NULL, func, &args[0]);
  pthread_create(&t2, NULL, func, &args[1]);
  pthread_create(&t3, NULL, func, &args[2]);
  pthread_create(&t4, NULL, func, &args[3]);
  pthread_join(t1, NULL);
  pthread_join(t2, NULL);
  pthread_join(t3, NULL);
  pthread_join(t4, NULL);
  printf("Finished\n");
  return 0;
}