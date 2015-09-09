#ifndef _AndQuery_h
#define _AndQuery_h

#include "Query.h"
#include "BinaryQuery.h"
#include "TextQuery.h"
#include <iostream>

class AndQuery: public BinaryQuery {
	friend Query operator&(const Query&, const Query&);
	AndQuery(const Query &left, const Query &right):
		BinaryQuery(left, right, "&") { std::cout << "AndQuery(l,r)" << std::endl;}
	QueryResult eval(const TextQuery&) const;
};

inline Query operator&(const Query &lhs, const Query &rhs)
{
	return std::shared_ptr<Query_base>(new AndQuery(lhs,rhs));
}

#endif
