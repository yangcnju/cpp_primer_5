#include "AndQuery.h"
#include <string>

QueryResult AndQuery::eval(const TextQuery &t) const
{
	return t.query("x");
}
