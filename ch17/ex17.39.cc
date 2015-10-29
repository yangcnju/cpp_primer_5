// Exercise 17.39: Write your own version of the seek program presented
// in this section.
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

int main()
{
	fstream inOut("trans.txt",fstream::ate | fstream::in | fstream::out);
	if(!inOut) {
		cerr << "Unable to access the stream." << endl;
		return EXIT_FAILURE;
	}

	auto end_mark = inOut.tellg();
	inOut.seekg(0, fstream::beg);
	size_t cnt = 0;
	string line;

	while(inOut 
	      && inOut.tellg() != end_mark
	      && getline(inOut,line)){
    cnt += line.size() + 1;
	  auto mark = inOut.tellg();
	  inOut.seekp(0, fstream::end);
	  inOut << cnt;
		if(mark!=end_mark) inOut << " ";
		inOut.seekg(mark);
	}

	inOut.seekp(0, fstream::end);
	inOut << "\n";

	inOut.close();

	return 0;
	}
