#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>

int main(int argc, char* argv[]){
	for(unsigned int i = 2; i < argc; ++i){
		if(fork()==0){
			execlp(argv[1], argv[1], argv[i], NULL);
			return 127;
		}
		wait(NULL);
	}
	printf("Finish\n");
	return 0;
}
