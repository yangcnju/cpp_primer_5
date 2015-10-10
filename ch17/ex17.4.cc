// Exercise 17.4: Write and test your own version of the findbook function.
#include <iostream>
#include <tuple>
#include <vector>
#include <string>
#include <algorithm>
#include <iterator>

#include "Sales_data.h"

using namespace std;

typedef tuple<vector<Sales_data>::size_type,
              vector<Sales_data>::const_iterator,
              vector<Sales_data>::const_iterator> matches;

vector<matches>
findItem(const vector<vector<Sales_data>> &files,
         const string &book)
{
	vector<matches> ret;
	for(auto it = files.cbegin(); it!=files.cend(); ++it){
		auto found = equal_range(it->cbegin(), it->cend(), 
		                         Sales_data(book), compareItem);
	  if(found.first!=found.second)
		  ret.push_back(make_tuple(it - files.cbegin(),
		                           found.first,found.second));	
	}
	return ret;
}

int main()
{
	vector<Sales_data> store1, store2, store3;
	store1.push_back(Sales_data("item1",3.0,1));
	store1.push_back(Sales_data("item1",2.9,1));
	store1.push_back(Sales_data("item2",4.0,2));
	store1.push_back(Sales_data("item3",5.0,3));
	store2.push_back(Sales_data("item1",3.1,9));
	store2.push_back(Sales_data("item2",4.0,2));
	store2.push_back(Sales_data("item3",5.0,3));
	store3.push_back(Sales_data("item1",3.2,1));
	store3.push_back(Sales_data("item2",4.0,2));
	store3.push_back(Sales_data("item3",5.0,3));

  vector<vector<Sales_data>> stores;
	stores.push_back(store1);
	stores.push_back(store2);
	stores.push_back(store3);

  auto result = findItem(stores, "item1");
	for(const auto &entry : result){
	  cout << get<0>(entry) << " ";
		for(auto iter = get<1>(entry) ; iter != get<2>(entry); ++iter){
	    cout << iter->name() << " " 
		       << iter->amount() << " "
		       << iter->price() << "\t";
		}
		cout << endl;
	}
	return 0;
}
