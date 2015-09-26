#ifndef _QueryResult_h
#define _QueryResult_h

#include "TextQuery.h"
#include <string>
#include <vector>
#include <memory>
#include <iostream>

class QueryResult {
friend std::ostream& print(std::ostream&, const QueryResult&);
public:
	using line_no = std::vector<std::string>::size_type;
	QueryResult(std::string s,
							std::shared_ptr<std::set<line_no>> p,
							std::shared_ptr<std::vector<std::string>> f):
		sought(s), lines(p), file(f) { std::cout << "QueryResul(s,ptr_line,file)" 
																	 << std::endl; }
private:
	std::string sought;
	std::shared_ptr<std::set<line_no>> lines;
	std::shared_ptr<std::vector<std::string>> file;
};

#endif
