#include "TextQuery.h"
#include "QueryResult.h"
#include <iostream>
#include <string>

// empty class defined just to show the inheritance.

class Query_base{
public:
	Query_base(const std::string &s = "") 
	{ std::cout << "Query_base " << std::endl; }
	virtual ~Query_base(){}
private:
};

class WordQuery : public Query_base{
public:
	WordQuery(const std::string &s = ""):Query_base(s)
	{ std::cout << "WordQuery " << std::endl; }
}
