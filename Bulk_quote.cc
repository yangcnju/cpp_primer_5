#include "Bulk_quote.h"

double Bulk_quote::net_price(std::size_t n) const
{
	if(n>min_qty)
		return (price - discount) * n;
	else
		return price * n;
}
