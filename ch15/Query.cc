#include "Query.h"
#include "WordQuery.h"
#include <iostream>
#include <string>

std::ostream&
operator<<(std::ostream &os, const Query &query)
{
	return os << query.rep();
}
