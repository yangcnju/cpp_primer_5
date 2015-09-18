#include <iostream>

using namespace std;

// (a) need typename for U
template <typename T, typename U, typename V> void f1(T, U, V)
{
	cout << "template void f1(T,U,V)" << endl;
}

// (b) should not reuse name
template <typename T> T f2(int &t)
{
	cout << "T f2(int &)" << endl;
	return T();
}

// (c) inline will be ignored
inline template <typename T> T foo(T, unsigned int *i)
{
	cout << "foo(T, unsigned int*)" << endl;
	return T();
}

// (d) need return type
template <typename T> void f4(T t1,T t2)
{
	cout << t1 << " " << t2 << " ";
	cout << "f4(T,T)" << endl;
}

// (e) will compile, but Ctype for char is hiden
typedef char Ctype;
template <typename Ctype> Ctype f5(Ctype a)
{
	cout << "f5(Ctype a)" << " " << a << endl;
	return Ctype();
}

int main()
{
	int i = 0;
	int j = 0;
	int k = 0;
	f1(i,j,k);

	f2<int>(i);

  unsigned int *uip = new unsigned int(1);
	foo(i,uip);
	delete uip;

	f4(i,j);

	f5(k);

	return 0;
}
