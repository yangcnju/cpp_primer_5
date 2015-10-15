// Exercise 17.30: Revise your function again this time to take a minimum
// and maximum value for the numbers that the function should return.

#include <random>
#include <iostream>
#include <string>
#include <ctime>

using namespace std;

unsigned int gen_num()
{
	static default_random_engine e;
	static uniform_int_distribution<unsigned> u(0,9);
	return u(e);
}

unsigned int gen_num_range(int min, int max)
{
	static default_random_engine e;
	static uniform_int_distribution<unsigned> u(min,max);
	return u(e);
}

int main()
{
	for(size_t i = 0; i < 10; ++i)
		cout << gen_num_range(10,20) << " ";
	cout << endl;

	return 0;
}
