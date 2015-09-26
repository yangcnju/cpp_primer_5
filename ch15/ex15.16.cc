// The class that implements a limited discount strategy (100)
#include "Quote.h"
#include "Bulk_disc_quote.h"
#include <iostream>

/*
double print_total(std::ostream &os, const Quote &item, std::size_t n)
{
	double ret = item.net_price(n);
	os << "ISBN: " << item.isbn()
		 << " # sold: " << n << " total due: " << ret << std::endl;
	return ret;
}
*/

using namespace std;

int main()
{
	Quote basic("12345",10.0);
	Bulk_disc_quote bulk("99999",10.0,5,2);
	print_total(cout, basic, 20);
	print_total(cout, bulk, 20);
	print_total(cout, bulk, 81);
	return 0;
}
