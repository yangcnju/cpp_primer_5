#include "Query.h"
#include <string>
#include <vector>
#include <map>
#include <set>
#include <memory>
#include <fstream>
#include <iostream>
#include <sstream>
#include <stdexcept>

TextQuery::TextQuery(std::ifstream& fin)
	: file(new std::vector<std::string>)
{
	std::string line;
	line_no ln = 0;
	while(getline(fin,line)){
		ln++;
		file->push_back(line);
		std::string word;
		std::istringstream iss(line);
		while(iss >> word){
			auto &lines = word_map[word];
			if(!lines)
				lines.reset(new std::set<line_no>);
			lines->insert(ln);
		}	
	}
}

TextQuery::QueryResult TextQuery::query(const std::string &sought) const
{
	static std::shared_ptr<std::set<line_no>> nodata(new std::set<line_no>);
	auto loc = word_map.find(sought);
	if(loc == word_map.end())
		return QueryResult(sought, nodata, file);
	else
		return QueryResult(sought, loc->second, file);
}

std::ostream& print(std::ostream &os, const TextQuery::QueryResult &qr)
{
	os << qr.sought << " occurs " << qr.lines->size() << " "
		 << "times." << std::endl;
	for(auto num : *qr.lines)
		os << "\t(line " << num << ") "
			 << *(qr.file->begin() + num-1) << std::endl;
	return os;
}
