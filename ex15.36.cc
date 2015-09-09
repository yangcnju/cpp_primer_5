// print constructor order

#include "QueryHeaders.h"
#include <iostream>
#include <string>

using namespace std;

int main()
{
	Query q = Query("fiery") & Query("bird") | Query("wind");
	cout << q.rep() << endl;
	return 0;
}
