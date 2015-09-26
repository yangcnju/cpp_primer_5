#include "Bulk_disc_quote.h"

std::size_t Bulk_disc_quote::max_qty = 100;	// although a magic number

double Bulk_disc_quote::net_price(std::size_t n) const
{
	if(n>=quantity && n<=max_qty){
		max_qty-=n;
		return (price - discount) * n;
	}
	else if(n>=quantity && n>max_qty){
		double temp = max_qty*(price-discount);
		double final_price =  price*(n-max_qty)+temp;
		max_qty = 0;
		return final_price;
	}
	else
		return price * n;
}
