#ifndef _Bulk_disc_quote_h
#define _Bulk_disc_quote_h

#include "Disc_quote.h"
#include <string>

class Bulk_disc_quote : public Disc_quote{
public:
	//Bulk_disc_quote() = default;
	//Bulk_disc_quote(const std::string &book, double price,
	//								std::size_t qty, double disc):
 	//	Disc_quote(book, price, qty, disc)	{}
	//	ex15.27 inherited constructors
	using Disc_quote::Disc_quote;
	double net_price(std::size_t) const override;
private:
	static std::size_t max_qty;
};	// class Bulk_disc_quote

#endif
