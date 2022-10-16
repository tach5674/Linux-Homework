#include <stdio.h>
#include <cstring>

int main(int argc, char* argv[]){
	int a, b, c;	
	sscanf(argv[2], "%d", &a);
	sscanf(argv[4], "%d", &b);
	if(!strcmp(argv[3], "+")){
		c = a + b;
		printf("%d\n", c);
	}
	
	if(!strcmp(argv[3], "*")){
		c = a * b;		
		printf("%d\n", c);
	}
	return 0;
}
