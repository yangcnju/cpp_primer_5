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

using namespace std;

int main(int argc, char **argv)
{
	string filename("");
	cout << "input filename: " << endl;
	cin >> filename;
	fstream fin(filename);
	vector<string> all_words;
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

	test_equal t;
	for(auto iter = all_words.begin(); iter!=all_words.end(); ++iter){
		string final_val = "??";
		string look_for = "=";
		if(t(*iter,look_for))
			*iter = final_val;
	}
	ostream_iterator<string> s_out(cout, " ");
	copy(all_words.begin(),all_words.end(),s_out);
	return 0;
}
