#include "TextQuery.h"
#include <string>
#include <vector>
#include <set>
#include <fstream>
#include <sstream>
#include <memory>
#include <iostream>

#include <tuple>

TextQuery::TextQuery(std::ifstream &is) 
  : file(new std::vector<std::string>)
{
	std::string text;
	while(getline(is,text)){
		file->push_back(text);
		int n = file->size()-1;
		std::istringstream line(text);
		std::string word;
		while(line >> word){
			auto &lines = wm[word];
			if(!lines)
				lines.reset(new std::set<TextQuery::line_no>);
			lines->insert(n);
		}
	}
}

std::tuple<std::string,
           std::shared_ptr<std::set<TextQuery::line_no>>,
           std::shared_ptr<std::vector<std::string>>>
	 TextQuery::query(const std::string &sought) const
{
	static std::shared_ptr<std::set<TextQuery::line_no>> 
		nodata(new std::set<TextQuery::line_no>);
	auto loc = wm.find(sought);
	if(loc == wm.end())
		return std::make_tuple(sought, nodata, file);
	else
		return std::make_tuple(sought, loc->second, file);
}

std::ostream &print(std::ostream &os, 
                    const std::tuple<std::string,
	           std::shared_ptr<std::set<typename TextQuery::line_no>>,
	           std::shared_ptr<std::vector<std::string>>> &qr)
{
	os << std::get<0>(qr) << " occurs " << (std::get<1>(qr))->size() << " "
		 << "times." << std::endl;
	for(auto num : *(std::get<1>(qr)))
		os << "\t(line " << num+1 << ") "
			 << *((std::get<2>(qr))->begin() + num) << std::endl;
	return os;
}
