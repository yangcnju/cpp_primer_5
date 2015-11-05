// Exercise 18.7: Define your Blob and BlobPtr classes from Chapter 16 to use
// function try blocks for their constructors.
#include "Blob.h"
#include <vector>
#include <string>
#include <iostream>

using namespace std;

int main(int argc, char **argv)
{
	vector<int> ivec {1,2,3,4,5};
	Blob<int> ib(ivec.begin(),ivec.end());
	cout << "size of ivec: " << ib.size() << endl;

	return 0;
}
