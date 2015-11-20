// Exercise 19.26: Explain these declarations and indicate whether they are
// legal:

#include <iostream>

using namespace std;

extern "C" int compute(int *, int);
//extern "C" double compute(double *, double);

int main(int argc, char **argv)
{
  int i = 1;
	int j = 2;
	cout << compute(&i,j) << endl;
	return 0;
}

extern "C" int compute(int *pti, int i)
{
  return *pti+i;
}
// illegal
//extern "C" double compute(double *ptd, double d)
//{
//  return *ptd+d;
//}
