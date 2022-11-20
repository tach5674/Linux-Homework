#include <unistd.h>
#include <stdio.h>

int main(void){
	int fd[2];
	pipe(fd);
	char buff = 'a';
	int n = 1;
	write(fd[1], &buff, 1);
	while(n){
		if(write(fd[1], &buff, 1) < 0)
			break;
		++n;
		
	}
	printf("%d", n);
}
