// ex 14.51 conversion sequences
#include <iostream>

struct LongDouble {
	LongDouble(double = 0.0) {}
	operator double() { std::cout << "operator double() "; return 0.1;}
	operator float() { std::cout << "operator float() "; return -0.1;}
};	// struct LongDouble

void calc(int i)
{
	std::cout << "void calc(int) ";
}

void calc(LongDouble ld)
{
	std::cout << "void calc(LongDouble) ";
}

int main(int argc, char **argv)
{
	double dval = 0.0;
	calc(dval);
	return 0;
}
