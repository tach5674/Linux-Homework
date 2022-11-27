#include <unistd.h>
#include <stdio.h>

int main(void){
	int fd[2];
	pipe(fd);
	int n = 1;
	char buff[1000];
	buff[0] = 'a'; 
	while(write(fd[1], &buff, n) > 0){
		for(int i = 0; i < n; ++i){
			buff[i] = 'a';
		}
		++n;
	}
	printf("%d", n);
}
