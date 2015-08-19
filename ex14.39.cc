// copied from ex14.38.cc
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <stdexcept>

class test_equal{
public:
	bool operator()(const std::string &s1, const std::string &s2) const{
		return s1 == s2;
	}
};	// class test_equal

class s_length{
public:
	s_length(size_t n): sz(n) 
	{if (n<1 || n>10) 
		throw std::out_of_range("n needs to be between 1 and 10.");
	}

	bool operator()(const std::string &s) const
	{ return s.size() == sz; }
	size_t size() const { return sz; }
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
	vector<size_t> counts(10,0);

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
		for(auto i = 0; i!=10; ++i){
			s_length t(i+1);
			if(t(*iter))
				++counts[i];
		}	
	}
	for(auto i = 0; i!=10; ++i){
			cout << "words of size " << i+1 << " occured: " 
					 << counts[i] << " times." << endl;
	}
	return 0;
}
