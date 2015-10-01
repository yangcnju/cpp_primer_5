// Exercise 16.60: Explain how make_shared (ch12.1.1, p.451) works

#include <memory>
#include <iostream>
#include <string>

using namespace std;

template <typename T, typename ... Args>
shared_ptr<T> my_make_shared(Args&&...args)
{
	shared_ptr<T> sp( new T(std::forward<Args>(args)...) );
	return sp;
}

int main()
{
	shared_ptr<int> isp = my_make_shared<int>(2);
	shared_ptr<int> isp0 = make_shared<int>(2);
	cout << "isp: " << *isp << endl;
	cout << "isp0: " << *isp0 << endl;
	return 0;
}
