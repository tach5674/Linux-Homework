#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char* argv[]){
	if(argc < 2){
		printf("%s\n", "No args");
		return 1;
	}
	int fd;
	fd = open(argv[1], O_RDWR);
	if(fd == -1){
		perror(argv[1]);
		//close(fd);
		return 2;
 	}
	char buff;
	while(read(fd, &buff, sizeof(buff)) > 0){
		if(buff >= 'a' && buff <= 'z'){
			buff -= 32;
			lseek(fd, -1, SEEK_CUR);
			write(fd, &buff, sizeof(buff));
			continue;
		}
		if(buff >= 'A' && buff <= 'Z'){
			lseek(fd, -1, SEEK_CUR);
			write(fd, &buff, sizeof(buff));
			continue;
		}
		if(buff >= '0' && buff <= '9'){
			lseek(fd, -1, SEEK_CUR);
			write(fd, "_", sizeof(buff));
		}
	}
	close(fd);
	return 0;
}
