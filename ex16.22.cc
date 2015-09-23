#include "TextQuery.h"
#include "QueryResult.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void runQueries(ifstream &infile)
{
	TextQuery tq(infile);
	while(true){
		cout << "enter word to look for, or q to quit: ";
		string s;
		if(!(cin>>s)||s=="q") break;
		print(cout,tq.query(s)) << endl;
	}
}

int main(int argc, char **argv)
{
	ifstream infile("ch16.1.1.cc");
	runQueries(infile);
	infile.close();
	return 0;
}
