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

int main()
{
	for(size_t i = 0; i < 10; ++i)
		cout << gen_num() << " ";
	cout << endl;

	return 0;
}
