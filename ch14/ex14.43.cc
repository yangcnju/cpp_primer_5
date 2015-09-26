#include <iostream>
#include <functional>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char **argv)
{
	vector<int> ivec {2,3,5};
	int test {1};
	while(test!=0){
		cout << "Enter an integer to test if divisible by \n"
				 << "any of 2 3 5 7 11 13 17 19. (Enter 0 to terminate):"
				 << endl;
		cin >> test;
		bool is_divisible = 0;
		is_divisible = count_if(ivec.cbegin(), ivec.cend(), 
														[test](int i) {return (test%i)==0;});
		cout << (is_divisible ? "Is divisible." : "Is not divisible") << endl;
	}
	return 0;
}
