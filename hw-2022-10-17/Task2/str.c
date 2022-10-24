#include "str.h"

int string_length(const char * str){
	int k = 0;  	
	while(*str != '\0'){
		++k;
		++str;
	}
	return k;
}
int num_digits(const char * str){
	int k = 0;
	for(int i = 0; i < string_length(str); ++i){
		if ((str[i] >= '0') && (str[i] <= '9')) 
			++k;
	}
	return k;
}
