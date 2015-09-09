#ifndef _Query_base_h
#define _Query_base_h

#include <string>
#include <iostream>
#include "TextQuery.h"
#include "QueryResult.h"
#include "Query.h"

class Query_base {
	friend class Query;
protected:
	Query_base() { std::cout << "Query_base()\t"; }
	using line_no = TextQuery::line_no;		// used in the eval function
	virtual ~Query_base() = default;
private:
	virtual QueryResult eval(const TextQuery&) const = 0;
	virtual std::string rep() const = 0;
};

#endif
