#ifndef BIG_UNSIGNED
#define BIG_UNSIGNED
class BigUnsigned{
	unsigned int num;
	BigUnsigned(const std::string &s);
	BigUnsigned operator+(BigUnsigned b);
	BigUnsigned operator*(BigUnsigned b);
};
#endif
