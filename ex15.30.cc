#include "Basket.h"
#include "Quote.h"
#include "Bulk_quote.h"
#include <iostream>
#include <string>

using namespace std;

int main()
{
	Basket qts;
	Bulk_quote b1("99999",14.0,4,4.0);
  Bulk_quote b2("10000",24.0,4,4.0);	
  Bulk_quote b3("20000",24.0,4,4.0);	
  Bulk_quote b4("30000",24.0,4,4.0);	
	Quote q1("0001",15.0);

	qts.add_item(q1);
	qts.add_item(b1);
	qts.add_item(b1);
	qts.add_item(b1);
	qts.add_item(b1);
	qts.add_item(b2);
	qts.add_item(b3);
	qts.add_item(b4);
	qts.total_receipt(cout);
	return 0;
}
