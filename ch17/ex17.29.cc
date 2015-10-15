// Exercise 17.29: Allow a seed by user

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

unsigned int gen_num_s(int s)
{
	static default_random_engine e(s);
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
		cout << gen_num_s(30) << " ";
	cout << endl;

	return 0;
}
