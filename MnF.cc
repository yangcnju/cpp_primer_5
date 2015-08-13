#include <iostream>
#include <string>
#include "Message.h"
#include "Folder.h"

using namespace std;

int main()
{
	Folder f1, f2;
	Message a("msg1");
	Message b("msg2");
	a.save(f1);
	a.save(f2);
	b.save(f1);
	b.remove(f1);
	cout << a.show() << endl;
	return 0;
}
