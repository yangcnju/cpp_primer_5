// Write your own versions of shared_ptr and unique_ptr
#include "my_ptrs.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;
using namespace my_ptrs;

int main()
{
	my_ptrs::shared_ptr<int> isp(new int(5));
	cout << *isp << " been used times: " << isp.usage() << endl;

	my_ptrs::shared_ptr<vector<int>> vsp;
	vsp->push_back(1);
	vsp->push_back(2);
	vsp->push_back(3);
	cout << vsp->size() << endl;
	cout << "vsp been used times: " << vsp.usage() << endl;

	my_ptrs::shared_ptr<int> isp2;
	isp2 = my_ptrs::make_shared<int>(new int(99));
	cout << *isp2 << " been used times: " << isp2.usage() << endl;

	my_ptrs::shared_ptr<int> isp3;
	cout << "usage for pointer pointing to 99: " << isp2.usage() << endl;
	isp3 = isp2;
	cout << "usage for pointer pointing to 99: " << isp3.usage() << endl;
	
	return 0;
}
