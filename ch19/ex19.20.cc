#include <iostream>
#include <fstream>
#include <string>
#include "Query.h"

using namespace std;

void runQueries(ifstream &infile)
{
	TextQuery tq(infile);
	while(true){
		cout << "enter word to look for, or q to quit: ";
		string s;
		if(!(cin >> s)|| s == "q") break;
		print(cout, tq.query(s)) << endl;
	}
}

int main()
{
	string filename;
	cout << "input filename: ";
	cin >> filename;
	ifstream fin(filename);
	runQueries(fin);
	fin.close();
	return 0;
}
