#include <iostream>
#include <string>

class PrintString{
public:
	PrintString(std::ostream &o = cout, char c = ' '):
		os(o), sep(c) {}
	void operator()(const string &s) const {os << s << sep;}
private:
	ostream &os;
	char sep;
};

