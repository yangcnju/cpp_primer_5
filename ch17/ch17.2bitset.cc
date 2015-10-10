#include <bitset>
#include <iostream>

using namespace std;

int main()
{
	bitset<32> bitvec3 ("100");
	unsigned long ulong = bitvec3.to_ulong();
	cout << "ulong = " << ulong << endl;
	return 0;
}
