#include <fcntl.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

void *func(int* arr[]) {
	int result;
	int a;
	sscanf(arr[1], "%d", &result);
	for(int i = 2; i < arr[0]; ++i){
		sscanf(arr[i], "%d", a);
		result += a;
	}
	printf("%d ", result);
}

int main(int args, char *argv[]) {
  int fd;
  int s, t, n;
  sscanf(argv[1], "%d", &s);
  sscanf(argv[2], "%d", &t);
  fd = open(argv[3], O_RDONLY);
  read(fd, &n, sizeof(n));
  int arr[n + 2];
  arr[0] = n;
  arr[1] = s;
  for (int i = 2; i < n; ++i) {
    read(fd, &arr[i], sizeof(n));
  }
  for (int i = 0; i < n; ++i) {
    printf("%d ", arr[i]);
  }

  pthread_t threads[t];
  for (int i = 0; i < t; ++i) {
    pthread_create(&threads[i], NULL, func, arr);
  }
  return 0;
}
