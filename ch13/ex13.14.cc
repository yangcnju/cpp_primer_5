#include <iostream>
#include <string>

class numbered{
public:
	numbered() : mysn(std::string("numbered constructor")) {}
	numbered(const std::string &s) : mysn(s) {}
	numbered& operator=(const numbered &n) {mysn = n.mysn+"+1"; return *this;}
	numbered(const numbered &n) : mysn(n.mysn+"+1") {}

	std::string mysn;
};	// class numbered

void f(const numbered &s) { std::cout << s.mysn << std::endl; }

int main()
{
	numbered a, b = a, c = b;
	f(a); f(b); f(c);
	return 0;
}
