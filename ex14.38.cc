#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <iostream>
#include <algorithm>

class test_equal{
public:
	bool operator()(const std::string &s1, const std::string &s2) const{
		return s1 == s2;
	}
};	// class test_equal

class s_length{
public:
	s_length(size_t n): sz(n) {}
	bool operator()(const std::string &s) const
	{ return s.size() == sz; }
private:
	size_t sz;
};	// class s_length

// not finished. ex14.41
// ////////////////////////////
using namespace std;

int main(int argc, char **argv)
{
	string filename("");
	cout << "input filename: " << endl;
	cin >> filename;
	fstream fin(filename);
	vector<string> all_words;
	size_t num = 0;
	if(fin){
		string line;
		while(getline(fin,line)){
			istringstream iline(line);
			string word;
			while(iline >> word)
				all_words.push_back(word);
		}
	} else
		cerr << "cannot open " + filename << endl;

	s_length t(5);
	for(auto iter = all_words.begin(); iter!=all_words.end(); ++iter){
		string final_val = "??";
		string look_for = "=";
		if(t(*iter))
			++num;
	}
	cout << "words of size 5 occured: " << num << " times." << endl;
	return 0;
}
