#ifndef _WordQuery_h
#define _WordQuery_h

#include "Query.h"
#include "Query_base.h"
#include "TextQuery.h"
#include "QueryResult.h"
#include <string>
#include <iostream>

class WordQuery: public Query_base {
	friend class Query;	// Query uses the WordQuery constructor
	WordQuery(const std::string &s): query_word(s) { std::cout << "WordQuery(s)" 
	                                                 << std::endl; }
	QueryResult eval(const TextQuery &t) const
		{ return t.query(query_word); }
	std::string rep() const { return query_word; }
	std::string query_word;
};

#endif
