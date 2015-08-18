#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>

class ReadString{
public:
	ReadString(std::istream &i = std::cin):
		is(i) {}
	std::string operator()(std::string &s) const; 
private:
	std::istream &is;
};

using namespace std;

int main(int argc, char **argv)
{
	ReadString r;
	string s;
	r(s);	
	cout << "The string we got: " << s << endl;

	cout << "---------------" << '\n' << "For a series of input:" << endl;
	vector<string> svec(5,"");
	for_each(svec.begin(),svec.end(),r);
	for_each(svec.begin(),svec.end(),[](const string &s) { cout << s << " "; });
	cout << endl;

	ostream_iterator<string> o_iter(cout, " ");
	copy(svec.begin(),svec.end(),o_iter);
	return 0;
}

std::string ReadString::operator()(std::string &s) const
{
	is >> s;
	if(!is)
		s = "";
	return s;
}
