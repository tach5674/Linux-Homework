#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char* argv[]){
	char* args[100];
	char buff;
	char arg[100];
	char pr[100];
	char filename[100];
	int i = 0;
	int j = 0;
	int fd = open(argv[1],  O_RDWR);
	
	while(read(fd, &buff, sizeof(buff)) > 0){
		if(j == 0){
			if(buff == ' '){
				++j;
				i = 0;
			}
			pr[i] = buff;
			++i;
			continue;
		}
		if(j == 1){
			if(buff == ' '){
				++j;
				i = 0; 
			}
			filename[i] = buff;
			++i;
			continue;

		}
		if(buff == ' '){
			args[j] = arg; 
			++j;
			i = 0;
		}
		arg[i] = buff;
		++i;
	}
	args[j+1] = NULL;
	close(fd);
	int fd1 = open(filename, O_RDWR);
	dup2(fd1, 0);
	execvp(pr, args);
	return 0;
}
