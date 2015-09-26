// examine multiple operands
#include <iostream>
#include <vector>
#include <set>

class Operands{
public:
	Operands():i(0),j(0),k(0),l(0),m(0),n(0) {}
	void operator()(int a, int b, int c, int d, int e, int f){
		i = a; j = b; k = c; l = d; m = e; n = f;
		std::cout << i << j << k << l << m << n << std::endl;	
	}
private:
	int i;
	int j;
	int k;
	int l;
	int m;
	int n;
};

int main(int argc, char **argv)
{
	Operands o;
	o(1,2,3,4,5,6);
	return 0;
}
