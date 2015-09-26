// ch15.8.1 Writing a Basket Class
#ifndef _Basket_h
#define _Basket_h

#include <set>
#include <memory>
#include <iostream>
#include "Quote.h"

class Basket {
public:
	// synthesized default constructor and copy-control
	
	//void add_item(const std::shared_prt<Quote> &sale)
	//	{ items.insert(sale); }
	void add_item(const Quote& sale)
	{ items.insert(std::shared_ptr<Quote>(sale.clone())); }
	void add_item(Quote&& sale)
	{ items.insert(std::shared_ptr<Quote>(std::move(sale).clone())); }
	double total_receipt(std::ostream&) const;
private:
	static bool compare(const std::shared_ptr<Quote> &lhs,
											const std::shared_ptr<Quote> &rhs)
	{ return lhs->isbn() < rhs->isbn(); }
	std::multiset<std::shared_ptr<Quote>, decltype(compare)*> items{compare};
};

#endif
