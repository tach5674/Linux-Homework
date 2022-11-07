#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char* argv[]){
	if(argc < 2){
		char* err = "No args\n";
		write(2, err, sizeof(err));
		return 1;
	}
	int fd;
	fd = open(argv[1], O_RDWR);
	if(fd == -1){
		perror(argv[1]);
		//close(fd);
		return 2;
 	}
	char buff[32];
	int n;
	while((n = read(fd, &buff, sizeof(buff))) > 0){
		for(int i = 0; i < n; ++i){
			if(buff[i] >= 'a' && buff[i] <= 'z'){
				buff[i] -= 32;
			}
			if(buff[i] >= '0' && buff[i] <= '9'){
				buff[i] = '_';
			}
		}
		lseek(fd, -n, SEEK_CUR);
		write(fd, &buff, n);
	}
	close(fd);
	return 0;
}
