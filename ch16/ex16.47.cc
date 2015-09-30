#include <utility>	// std::forward<T>
#include <iostream>
#include <vector>
#include <string>

template <typename F, typename T1, typename T2>
void my_flip(F f, T1 &&t1, T2 &&t2)
{
	f(std::forward<T1>(t2), std::forward<T2>(t1));
}


template <typename F, typename T1, typename T2>
void my_flip2(F f, T1 &&t1, T2 &&t2)
{
	f(t2, t1);
}

using namespace std;

void f1(vector<int>::const_iterator b, vector<int>::const_iterator e)
{
	while(b!=e){
		cout << *b << " ";
		++b;
	}
	cout << endl;
}

void f2(int &&i, int &&j)
{
	cout << i << " " << j << endl;
}

void f3(int &i, int &j)
{
	cout << i << " " << j << endl;
}

int main()
{
	vector<int> ivec {1,2,3,4,5,6,7,8};
	my_flip(f1, ivec.end(), ivec.begin());	// notice that end and 
	                                        // begin was flipped.
	cout << ivec[0] << endl;

	my_flip(f2,1,2);
	int a = 1; int b = 2;
	my_flip(f2,std::move(a),std::move(b));
	// my_flip2(f2,std::move(a),std::move(b)); // will not compile, rvalue
	                                           // became lvalue already
	my_flip(f3,a,b);
	my_flip2(f3,a,b);
	// const int ca = 1; const int cb = 2;
	// my_flip(f2,ca,cb); // will not compile
	return 0;
}
