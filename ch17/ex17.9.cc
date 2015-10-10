#include <bitset>
#include <iostream>
#include <string>

using namespace std;

int main()
{
	ostream& os(cout);
	bitset<64> bitvec(32);	// 0...0100000
	os << "bitvec(32): " << bitvec << endl;

	bitset<32> bv(1010101);	// This is big... so only the bitnum within length.
	os << "bv(1010101): " << bv << endl;

	string bstr ("101001");
	bitset<8> bv2(bstr);
	os << "bv(bstr) with bstr(\"101001\") : " << bv2 << endl;
	return 0;
}
