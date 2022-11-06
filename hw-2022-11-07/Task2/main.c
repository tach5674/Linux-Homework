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
	int t = 0;
	int fd = open(argv[1],  O_RDWR);
	/*
	args[0] = "wc";
	args[1] = "-w";
	args[2] = NULL;
	pr[0] = 'w';
	pr[1] = 'c';
	filename[0] = 't';
	filename[1] = 'a';
	filename[2] = 's';
	filename[3] = 'k';
	*/
	//Option 1
	/*
	dup2(fd, 0);
	scanf("%s", pr);
	scanf("%s", filename);
	while(scanf("%s", args[j]) > 0){
		++j;
	}
	args[j] = NULL;
	*/
	//Option 2
	/*
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
			args[t] = arg;
			++t;
			i = 0;
		}
		arg[i] = buff;
		++i;
	}*/
	//args[t+1] = NULL;
	
	//close(fd);
	int fd1 = open(filename, O_RDWR);
	dup2(fd1, 0);
	execvp(pr, args);
	return 0;
}
