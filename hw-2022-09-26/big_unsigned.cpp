#include <iostream>
#include <string>
#include "big_unsigned.hpp"

using namespace std;

BigUnsigned::BigUnsigned(const string &s):num(stoi(s)){}
BigUnsigned BigUnsigned::operator+(BigUnsigned b){
	b.num += this->num;
	return b;
}
BigUnsigned BigUnsigned::operator*(BigUnsigned b){
	b.num *= this->num;
	return b; 
}
