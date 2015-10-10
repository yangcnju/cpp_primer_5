#include <bitset>
#include <iostream>
#include <string>

using namespace std;

int main()
{
	bitset<32> b1;
	b1 |= 1UL << 1;
	b1 |= 1UL << 2;
	b1 |= 1UL << 3;
	b1 |= 1UL << 5;
	b1 |= 1UL << 8;
	b1 |= 1UL << 13;
	b1 |= 1UL << 21;
	cout << b1 << endl;

	bitset<32> b2;
	b2.set(1);
	b2.set(2);
	b2.set(3);
	b2.set(5);
	b2.set(8);
	b2.set(13);
	b2.set(21);
	cout << b2 << endl;

	return 0;
}
