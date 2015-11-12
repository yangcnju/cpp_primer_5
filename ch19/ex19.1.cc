// Exercise 19.1: Write your own operator new (size_t) function using malloc
// and use free to write the operator delete (void*) function.

#include <cstdlib>
#include <iostream>
#include <string>
#include <stdexcept>

using std::malloc;
using std::bad_alloc;
using std::cout;
using std::endl;
using std::string;

void *operator new (size_t sz) {
	if (void *mem = malloc(sz))
		return mem;
	else
		throw bad_alloc();
}

//void *operator delete(void *mem) noexcept
//{ free(mem); }

int main()
{
	string *ptrs = new string("demo");
	cout << *ptrs << endl;
	delete ptrs;
	return 0;
}
