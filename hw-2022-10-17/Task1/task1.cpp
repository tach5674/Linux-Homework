#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char* argv[]){
	for(int i = 1; i < argc; ++i){
		if(fork() == 0){
			execlp(argv[i], argv[i], NULL);
			return 127;
		}
		int status;
		wait(&status);
		if(WIFEXITED(status) && WEXITSTATUS(status) == 0){
			return 0;
		}
	} 
	return 0;
}
