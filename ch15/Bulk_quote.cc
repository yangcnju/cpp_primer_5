#include "Bulk_quote.h"
#include <iostream>

std::size_t Bulk_quote::max_qty = 100;		// maximum number of copies for
																					// discount price

// constructors
Bulk_quote::Bulk_quote(const Bulk_quote &b):
	Quote(b), min_qty(b.min_qty), discount(b.discount)
	{ std::cout << "Bulk_quote(const Bulk_quote&)" << std::endl; }

Bulk_quote::Bulk_quote(Bulk_quote &&b):
	Quote(std::move(b)), min_qty(b.min_qty), discount(b.discount)
	{ std::cout << "Bulk_quote(Buok_quote&&)" << std::endl; }

Bulk_quote& Bulk_quote::operator=(const Bulk_quote &b)
{
	Quote::operator=(b);
	min_qty = b.min_qty;
	discount = b.discount;
	return *this;
}

Bulk_quote& Bulk_quote::operator=(Bulk_quote &&b)
{
	Quote::operator=(std::move(b));
	min_qty = b.min_qty;
	discount = b.discount;
	return *this;
}

double Bulk_quote::net_price(std::size_t n) const
{
	if(n>=min_qty && n<max_qty){
		max_qty-=n;
		return (price - discount) * n;
	}
	else if(n>=min_qty && n>=max_qty){
		double temp = max_qty*(price-discount);
		double final_price =  price*(n-max_qty)+temp;
		max_qty = 0;
		return final_price;
	}
	else
		return price * n;
}

std::vector<std::string> Bulk_quote::debug() const 
{
	std::vector<std::string> dats;
	dats.push_back("max_qty");
	dats.push_back("min_qty");
	dats.push_back("discount");
	return dats;
}
