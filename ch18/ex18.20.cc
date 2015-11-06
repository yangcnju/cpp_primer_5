// Exercise 18.20: In the following code, determine which function, if any,
// matches the call to compute. List the candidate and viable functions. What
// type conversions, if any, are applied to the argument to match the parameter
// in each viable function?

#include <iostream>

using namespace std;

namespace primerLib {
	void compute();
	void compute(const void *);
}

//using primerLib::compute;
void compute(int);
void compute(double, double = 3.4);
void compute(char *, char* = 0);

void f()
{
	compute(0);
}

int main()
{
  using primerLib::compute;
	f();
	return 0;
}

void primerLib::compute()
{
	cout << "primerLib::compte()" << endl;
}

void primerLib::compute(const void *)
{
	cout << "primerLib::compte(const void *)" << endl;
}

void compute(int i)
{
	cout << "compute(int)" << endl;
}

void compute(double d, double d2)
{
	cout << "compute(double,double) " << endl;
}

void compute(char *ptrc, char *ptrc2)
{
	cout << "compute(char *, char*)" << endl;
}
