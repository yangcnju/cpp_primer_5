// Exercise 17.3: TextQuery with tuple instead of QueryResult.
#ifndef _TextQuery_h
#define _TextQuery_h

#include <vector>
#include <map>
#include <set>
#include <string>
#include <fstream>	//ifstream
#include <iostream>
#include <memory> 	// shared_ptr

#include <tuple>

class TextQuery {
public:
	using line_no = std::vector<std::string>::size_type;
	TextQuery(std::ifstream&);
	std::tuple<std::string,
	           std::shared_ptr<std::set<line_no>>,
	           std::shared_ptr<std::vector<std::string>>>
 	  query(const std::string&) const;
private:
	std::shared_ptr<std::vector<std::string>> file;
	std::map<std::string,
					 std::shared_ptr<std::set<line_no>>> wm;
};

std::ostream &print(std::ostream &os, 
                    const std::tuple<std::string,
	           std::shared_ptr<std::set<typename TextQuery::line_no>>,
	           std::shared_ptr<std::vector<std::string>>> &qr);

#endif
