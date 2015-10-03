// Exercise 17.3: Rewrite the TextQuery programs from ch12.3 (p. 484)
// to use a tuple instead of the QueryResult class. Explain which design
// you think is better and why.

#include "TextQuery.h"

#include <string>
#include <iostream>
#include <fstream>

// from page 486
void runQueries(std::ifstream &infile)
{
	TextQuery tq(infile);
	while(true){
		std::cout << "enter word to look for, or q to quit: ";
		std::string s;
		if(!(std::cin>>s) || s == "q") break;
		print(std::cout, tq.query(s)) << std::endl;
	}
}

using namespace std;

int main()
{
	ifstream fin("ex17.3.cc");
	runQueries(fin);
	fin.close();
	return 0;
}
