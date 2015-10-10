#include <bitset>
#include <iostream>
#include <string>

using namespace std;

template <unsigned N>
class quiz_track : public bitset<N> {
public:
  using bitset<N>::bitset;
  int intform() const { return bitset<N>::to_ulong(); }
 
  void update_answer(size_t pos, bool ans);
private:
};	// quiz_track


int main() 
{
	quiz_track<10> q1;
	q1.set(9);
	cout << q1 << endl;
	cout << q1.intform() << endl;

	q1.update_answer(5,true);
	cout << q1 << endl;
	return 0;
}

template <unsigned N>
inline void quiz_track<N>::update_answer(size_t pos, bool ans)
{
	if(ans)
		bitset<N>::set(pos-1);
	else
		bitset<N>::reset(pos-1);
}
