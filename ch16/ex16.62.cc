// Exericse 16.62: Define your own version of hash<Sales_data> and define an
// unordered_multiset of Sales_data objects. Put several transactions into the
// container and print its contents.

#include "Sales_data.h"
#include "hash_sales_data.h"
#include <unordered_set>	// unordered_multiset<T>
#include <iostream>
#include <string>

using namespace std;

bool eqOp(const Sales_data &lhs, const Sales_data &rhs)
{
	return lhs.name() == rhs.name();
}

int main()
{
	const auto hasher = hash<Sales_data>();
  using SD_multiset = unordered_multiset<Sales_data, 
                                         decltype(hasher),
                                         decltype(eqOp)*>;
	SD_multiset bookstore(42, hasher, eqOp);
	Sales_data sd1("demo01",30.5,1);
	Sales_data sd2("demo02",40.5,2);
	bookstore.insert(sd1);
	bookstore.insert(sd2);
	cout << bookstore.size() << endl;
	for(auto i : bookstore)
		cout << i << endl;
	return 0;
}
