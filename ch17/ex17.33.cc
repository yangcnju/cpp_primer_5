#include <stdexcept>
#include <string>
#include <fstream>
#include <map>
#include <vector>
#include <iostream>
#include <sstream>
#include <random>
#include <ctime>

using namespace std;

map<string,vector<string>> buildMap(ifstream &map_file);

const string &
transform(const string &s, const map<string,vector<string>> &m);

int main(int argc, char **argv)
{
	ifstream map_file{"trans.txt"};
	auto trans_map = buildMap(map_file);
	map_file.close();
	ifstream input("demo.txt");
	string text;
	while(getline(input,text)){
		istringstream stream(text);
		string word;
		bool firstword = true;
		while(stream >> word){
			if (firstword)
				firstword = false;
			else
				cout << " ";
			cout << transform(word, trans_map);
		}
		cout << endl;
	}
	input.close();
}


map<string,vector<string>> buildMap(ifstream &map_file)
{
	map<string,vector<string>> trans_map;
	string key;
	string value;
	while(map_file >> key && getline(map_file, value))
		if(value.size()>1)
			trans_map[key].push_back(value.substr(1));
		else
			throw runtime_error("no rule for " + key);
	return trans_map;
}

const string &
transform(const string &s, const map<string,vector<string>> &m)
{
	auto map_it = m.find(s);
	static default_random_engine e(time(0));
	static uniform_int_distribution<unsigned> u(0,16);
	if(map_it!=m.cend()){
		size_t sz = (map_it->second).size();
		const size_t pos = u(e)%sz;
		return (map_it->second)[pos];
	}
	else
		return s;
}
