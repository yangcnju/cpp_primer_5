// print constructor order

#include "QueryHeaders.h"
#include <iostream>
#include <string>

using namespace std;

int main()
{
	//ilegal, BinaryQuery is an abstract class
	BinaryQuery a = Query("fiery") & Query("bird");

	//ilegal, AndQuery operator '&' returns a Query obj
	AndQuery b = Query("fiery") & Query("bird");

	//ilegal, OrQuery do not have the operator '&', and returns only Query obj
	OrQuery c = Query("fiery") & Query("bird");
	return 0;
}
