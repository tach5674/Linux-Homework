#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <ctype.h>

int main(int argc, char* argv[]){
	if(argc < 3) 
		return 1;
	char buff;

	int fd1;
	if((fd1 = open(argv[1], O_RDONLY)) == -1){
		perror(argv[1]);
		return 1;
	}

	int fd2;
	if((fd2 = open(argv[2], O_RDWR | O_CREAT | O_TRUNC, 0600)) == -1){
		perror(argv[2]);
		return 1;
	}

	while(read(fd1, &buff, 1) != 0){
		if(isdigit(buff))
			buff = 'X';
		write(fd2, &buff, 1);
	}
	
	close(fd1);
	close(fd2);

	return 0;
}
