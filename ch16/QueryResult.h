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
		sought(s), lines(p), file(f) { std::cout << "QueryResult(s,ptr_line,file)" 
																	 << std::endl; }
	std::set<line_no>::iterator begin() { return (*lines).begin(); }
	std::set<line_no>::iterator end() { return (*lines).end(); }
	std::shared_ptr<std::vector<std::string>> get_file() const { return file; }
private:
	std::string sought;
	std::shared_ptr<std::set<line_no>> lines;
	std::shared_ptr<std::vector<std::string>> file;
};

#endif
