#ifndef _TextQuery_h
#define _TextQuery_h

#include <vector>
#include <map>
#include <set>
#include <string>
#include <fstream>	//ifstream
#include <memory> 	// shared_ptr

class QueryResult;

class TextQuery {
public:
	using line_no = std::vector<std::string>::size_type;
	TextQuery(std::ifstream&);
	QueryResult query(const std::string&) const;
private:
	std::shared_ptr<std::vector<std::string>> file;
	std::map<std::string,
					 std::shared_ptr<std::set<line_no>>> wm;
};

#endif
