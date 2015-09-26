// Write a function that takes a reference to a container and prints
// the elements in that container. Use the container's size_type and
// size members to control the loop that prints the elements
#include <iostream>
#include <vector>
#include <list>
#include <set>
#include <string>

class p_container {
public:
	p_container(std::ostream &s = std::cout) : os(s) {}

	template <typename T>
		void operator()(const T &t) const
		{
			// ex16.19
			/*
			for(auto i : t)
				os << i << " ";
			os << std::endl;
			*/
			// ex16.20
			for(auto iter = t.begin(); iter != t.end(); ++iter)
				os << *iter;
			os << std::endl;
		}
private:
	std::ostream &os;
};	// class p_container

using namespace std;

int main(int argc, char **argv)
{
	vector<int> ivec {1,2,3,4,5,6,7,8};
	list<string> slst {"aaa","bb","cccc"};
	set<int> iset {1,2,3,4};	

	p_container pc;
	pc(ivec);
	pc(slst);
	pc(iset);

	return 0;
}
