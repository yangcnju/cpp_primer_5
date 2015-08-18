#include <string>
#include <iostream>

class if_n_else{
public:
	bool operator()(const std::string &s, int i, int j);
};

bool if_n_else::operator()(const std::string &s, int i, int j)
{
	return s.size() < 4 ? i : j;
}

using namespace std;

int main()
{
	if_n_else test;
	cout << test("ha",1,0) << endl;
	cout << test("longer",1,0) << endl;
	return 0;
}
