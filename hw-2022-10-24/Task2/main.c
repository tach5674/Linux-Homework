#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char* argv[]){
	if(argc < 3) return 1;
	char prebuff[32];
	int buff; 
	int a;
	if(!strcmp(argv[1], "save")){ 
		int fd; 
		if((fd = open(argv[2], O_RDWR | O_CREAT | O_TRUNC, 0600)) == -1){
			perror(argv[2]);
			return 1;
		}
		while(a = scanf("%d", &buff) == 1){
			//sscanf(prebuff, "%d", &buff);
			write(fd, &buff, sizeof(int));
			if(getchar() == '\n') break;
		}
		if(a != 1) return 1;
		close(fd);
		return 0;
	}
	if(!strcmp(argv[1], "print")){
		int fd;
		if((fd = open(argv[2], O_RDONLY)) == -1){
			perror(argv[2]);
			return 1;
		}
		while(read(fd, &buff, sizeof(int)) > 0){
			printf("%d ", buff);
		}
		return 0;
	}
	return 0;
}

