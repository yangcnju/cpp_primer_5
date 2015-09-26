#ifndef _OrQuery_h
#define _OrQuery_h

#include "Query.h"
#include "BinaryQuery.h"
#include "TextQuery.h"
#include <memory>
#include <iostream>
#include <string>

class OrQuery: public BinaryQuery {
	friend Query operator|(const Query&, const Query&);
	OrQuery(const Query &left, const Query &right):
		BinaryQuery(left, right, "|") {std::cout << "OrQuery(l,r)" << std::endl;}
	QueryResult eval(const TextQuery&) const;
};

inline Query operator|(const Query &lhs, const Query &rhs)
{
	return std::shared_ptr<Query_base>(new OrQuery(lhs,rhs));
}

#endif
