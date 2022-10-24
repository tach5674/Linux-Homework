#include <stdio.h>

int main(int argc, char* argv[]){
	int buff;
	int i = 0;
	int fd = open(argv[2], O_RDWR | O_CREAT, 0600); 
	if(argv[1] == "save"){ 
		while(scanf("%d", &buff) != -1){
			
			++i;
		}
	}
}

