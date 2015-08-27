// The class that implements a limited discount strategy (100)
#include "Quote.h"
#include "Bulk_quote.h"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

double print_total(std::ostream &os, const Quote &item, std::size_t n)
{
	double ret = item.net_price(n);
	os << "ISBN: " << item.isbn()
		 << " # sold: " << n << " total due: " << ret << std::endl;
	return ret;
}

void print_dats(const Quote &q)
{
	std::vector<std::string> dats;
	dats = q.debug();
	std::ostream_iterator<std::string> o_iter(std::cout, " ");
	copy(dats.cbegin(),dats.cend(),o_iter);
	std::cout << std::endl;
}

using namespace std;

int main()
{
	Quote basic("12345",10.0);
	Bulk_quote bulk("99999",10.0,5,2);
	print_total(cout, basic, 20);
	print_total(cout, bulk, 20);
	print_total(cout, bulk, 81);

	//ex15.11
	print_dats(basic);
	print_dats(bulk);		// called by reference, dynamic binding
	return 0;
}
