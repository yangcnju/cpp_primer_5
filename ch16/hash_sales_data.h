#ifndef _hash_sales_data_h
#define _hash_sales_data_h

#include "Sales_data.h"
#include <string>
#include <functional>

class Sales_data;

namespace std {
template <>
struct hash<Sales_data>
{
public:
	typedef size_t result_type;
	typedef Sales_data argument_type;
	size_t operator() (const Sales_data &s) const;
};	// class hash<Sales_data>

size_t
hash<Sales_data>::operator()(const Sales_data &s) const
{
	return std::hash<std::string>()(*(s.item_name)) ^
		     std::hash<unsigned>()(*(s.q)) ^
				 std::hash<double>()(s.p);
}
}

#endif
