#include <bitset>
#include <iostream>
#include <string>

using namespace std;

template <unsigned N>
class quiz_track : public bitset<N> {
public:
 using bitset<N>::bitset;
 int intform() const { return bitset<N>::to_ulong(); }
private:
};	// quiz_track

int main() 
{
	quiz_track<10> q1;
	q1.set(9);
	cout << q1 << endl;
	cout << q1.intform() << endl;
	return 0;
}
