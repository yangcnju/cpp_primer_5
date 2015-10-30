// Exercise 18.3: There are two ways to make the previous code work correctly
// if an exception is thrown. Describe them and implement them.

#include <iostream>
#include <fstream>
#include <exception>
#include <stdexcept>
#include <vector>
#include <string>

using namespace std;

void exercise(int *b, int *e)
{
	vector<int> v(b,e);
	int *p = new int[v.size()];
	ifstream in("ex18.3.cc");
	try{
		int i;
		while(in >> i){
			v.push_back(i);
		}
		range_error r("demo error.");
		throw r;
	}catch(exception &e){
		in.close();
		delete [] p;
		cout << e.what() << endl;
	}
}

int main()
{
	int iptrs[10] = {0,1,2,3,4,5,6,7,8,9};
	exercise(begin(iptrs),end(iptrs));
	
	return 0;
}
