#include "Bulk_quote.h"

std::size_t Bulk_quote::max_qty = 100;		// maximum number of copies for
																					// discount price

double Bulk_quote::net_price(std::size_t n) const
{
	if(n>min_qty && n<max_qty){
		max_qty-=n;
		return (price - discount) * n;
	}
	else if(n>min_qty && n>=max_qty){
		double temp = max_qty*(price-discount);
		double final_price =  price*(n-max_qty)+temp;
		max_qty = 0;
		return final_price;
	}
	else
		return price * n;
}
