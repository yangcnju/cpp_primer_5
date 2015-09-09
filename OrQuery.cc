#include "OrQuery.h"
#include <string>

QueryResult OrQuery::eval(const TextQuery &t) const
{
	return t.query("x");
}
