// Exercise 17.13: Write an integral object that contains the correct
// answers for the true/false quiz. Use it to generate grades on the 
// quiz for the data structure from the previous two exercies.
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

template <unsigned N>
class genGrade {
public:
	genGrade(const quiz_track<N> &k) : key(k) {} 
	int score(const quiz_track<N> &ans) const; 
	bitset<N> show_key() const { return key; }
private:
	quiz_track<N> key;
};	// class grade


int main() 
{
	quiz_track<10> q1;
	q1.set(9);
	cout << q1 << endl;
	cout << q1.intform() << endl;

	q1.update_answer(5,true);
	cout << q1 << endl;

	string key_str = "0111010110";
	quiz_track<10> key(key_str);
	genGrade<10> g(key);
	cout << "answer: " << q1 << endl;
	cout << "correct answer: " << g.show_key() << endl;
	cout << (~(q1^g.show_key())) << endl;
	cout << g.score(q1) << endl;
	return 0;
}

// Implementations.
template <unsigned N>
inline void quiz_track<N>::update_answer(size_t pos, bool ans)
{
	if(ans)
		bitset<N>::set(pos-1);
	else
		bitset<N>::reset(pos-1);
}

template <unsigned N>
int genGrade<N>::score(const quiz_track<N> &ans) const
{
	bitset<N> result = ~(ans ^ key);
	return result.count()* 100 / result.size();
}
