// For each labeled statement explain what, if any, instantiations happend.
// If a template is instantiated, explain why; if not, explain why not.
#include <string>
#include <iostream>

using namespace std;

template <typename T> class Stack {
public:
	Stack() { std::cout << "Construction" << std::endl; }
};

void f1(Stack<char>);		// (a) Instantiation happens by Stack<char>

class Exercise {
	Stack<double> &rsd;		// (b) not going to happen. Not used at all.
	Stack<int> si;        // (c) same as (b)
};

int main()
{
	Stack<char> *sc = nullptr; // (d) happens by variable definition.
	f1(*sc);              // (e) already initialized. 
	int iObj = sizeof(Stack<string>);	// (f) happens by definition.
	return 0;
}

void f1(Stack<char> Sc)
{}
