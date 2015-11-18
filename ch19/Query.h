#ifndef _Query_h
#define _Query_h

#include <string>
#include <vector>
#include <map>
#include <set>
#include <memory>
#include <fstream>
#include <iostream>


class TextQuery{
public:
  class QueryResult;

	using line_no = std::vector<std::string>::size_type;
	TextQuery(std::ifstream&);
	QueryResult query(const std::string&) const;
private:
	std::shared_ptr<std::vector<std::string>> file;
	std::map<std::string,std::shared_ptr<std::set<line_no>>> word_map;
};	// class TextQuery

class TextQuery::QueryResult{
	friend std::ostream& print(std::ostream&, const QueryResult&);
public:
	QueryResult(std::string s,
							std::shared_ptr<std::set<line_no>> p,
							std::shared_ptr<std::vector<std::string>> f):
		sought(s), lines(p), file(f) {}
private:
	std::string sought;
	std::shared_ptr<std::set<line_no>> lines;
	std::shared_ptr<std::vector<std::string>> file;
};	// class QueryResult

#endif
