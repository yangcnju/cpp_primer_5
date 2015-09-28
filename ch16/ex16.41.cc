#include <iostream>
#include <type_traits>
#include <numeric>
#include <vector>

template <typename It>
auto sum(It beg, It end) -> 
 typename std::remove_reference<decltype(*beg)>::type
{
	typedef typename std::remove_reference<decltype(*beg)>::type sum_type;
  sum_type s = std::accumulate(beg,end,sum_type()); 
  return s;
}

using namespace std;

int main()
{
	vector<int> ivec {1,2,3,4,5,6,7,8,9,10};
	cout << sum(ivec.begin(),ivec.end()) << endl;
	return 0;
}
