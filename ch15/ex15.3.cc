#include "Quote.h"
#include "Bulk_quote.h"
#include <iostream>

double print_total(std::ostream &os, const Quote &item, std::size_t n)
{
	double ret = item.net_price(n);
	os << "ISBN: " << item.isbn()
		 << " # sold: " << n << " total due: " << ret << std::endl;
	return ret;
}

using namespace std;

int main()
{
	Quote basic("12345",10.0);
	Bulk_quote bulk("99999",5.0);
	print_total(cout, basic, 20);
	print_total(cout, bulk, 20);
	return 0;
}
