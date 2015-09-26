#include "ch15.5.h"

int main()
{
	Pub_Derv d1;
	Priv_Derv d2;
	Prot_Derv d3;
	d1.pub_mem();
	Derived_from_Public dd1;
	Derived_from_Private dd2;
	Derived_from_Protected dd3;

	d1.memfcn(d1);
	//d2.memfcn(d1);
	d3.memfcn(d1);
	dd1.memfcn(d1);
	//dd2.memfcn(d1);
	dd3.memfcn(d1);

	return 0;
}
