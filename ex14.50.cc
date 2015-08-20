#include <iostream>

struct LongDouble {
	LongDouble(double = 0.0) {}
	operator double() { std::cout << "operator double() "; return 0.1;}
	operator float() { std::cout << "operator float() "; return -0.1;}
};	// struct LongDouble

int main(int argc, char **argv)
{
	LongDouble ldObj;
	int ex1 = ldObj;		// ambiguous
	float ex2 = ldObj;
	return 0;
}
