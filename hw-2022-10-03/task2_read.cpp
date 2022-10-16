#include "task2_read.hpp"
#include <stdio.h>
void read_and_invert(){
	int n = 0;
	char str[80];
	int ch;
	while((ch = getchar()) != '\n' && ch != EOF){
		str[n] = ch;
		++n;
	}
	for(int i = n-1; i >= 0; --i){
		putchar(str[i]);
	}
	putchar('\n');
}

