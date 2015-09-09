#ifndef _Query_h
#define _Query_h

#include "Query_base.h"
#include "QueryResult.h"
#include "WordQuery.h"
#include <memory>
#include <string>
#include <iostream>

class Query {
	friend Query operator~(const Query&);
	friend Query operator|(const Query&, const Query&);
	friend Query operator&(const Query&, const Query&);
	friend std::ostream& operator<<(std::ostream&, const Query&);
public:
	Query(const std::string&);
	QueryResult eval(const TextQuery &t) const
		{return q->eval(t);}
	std::string rep() const { return q->rep(); }
private:
	Query(std::shared_ptr<Query_base> query) : q(query) {}
	std::shared_ptr<Query_base> q;
};

std::ostream& operator<<(std::ostream&, const Query&);

inline
Query::Query(const std::string &s) : q(new WordQuery(s)) 
{ std::cout << "Query(string)" << std::endl; }

#endif
