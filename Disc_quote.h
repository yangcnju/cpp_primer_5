// ch15.4 Abstract Base Classes

#ifndef _Disc_quote_h
#define _Disc_quote_h

#include <string>
#include "Quote.h"

class Disc_quote : public Quote {
public:
	Disc_quote() = default;
	Disc_quote(const std::string &book, double price,
						 std::size_t qty, double disc):
		Quote(book, price), quantity(0), discount(disc) {}

	double net_price(std::size_t) const = 0;		// pure virtual
protected:
	std::size_t quantity = 0;
	double discount = 0.0;
};

#endif
