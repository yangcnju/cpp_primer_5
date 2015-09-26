#include <iostream>
#include <string>
#include "Quote.h"
#include "Bulk_quote.h"

using namespace std;

int main()
{
	Quote q;
	Bulk_quote b;
	Bulk_quote b2(b);
	cout << "net_price q of quantity 10: " << q.net_price(10) << endl;
	Quote *qptr = &q;
	qptr = &b;
	cout << "-----------" << endl;
	Bulk_quote b3 = std::move(b);
	cout << " ----------" << endl;
	Bulk_quote &&b4 = Bulk_quote();
	cout << "-----------" << endl;
	return 0;
}
