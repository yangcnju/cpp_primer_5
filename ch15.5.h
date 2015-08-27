#ifndef _ch15_5_cc
#define _ch15_5_cc

#include <string>
#include <iostream>

// page 612
class Base{
public:
	Base() = default;
	void pub_mem() { std::cout << "pub_mem()" << std::endl; }
	void memfcn(Base &b) { b = *this; }
protected:
	int prot_mem;
private:
	char priv_mem;
};

struct Pub_Derv : public Base {
	int f() { return prot_mem; }
	void memfcn(Base &b) { b = *this; }
};

// own version
struct Prot_Derv : protected Base {
	int f() { return prot_mem; }
	void memfcn(Base &b) { b = *this; }
};

struct Priv_Derv : private Base {
	int f1() const { return prot_mem; }
	//void memfcn(Base &b) { b = *this; }
};

// page 613
struct Derived_from_Public : public Pub_Derv {
	int use_base() { return prot_mem; }
	void memfcn(Base &b) { b = *this; }
};

struct Derived_from_Private : public Priv_Derv {
	//void memfcn(Base &b) { b = *this; }
};

struct Derived_from_Protected : public Prot_Derv {
	void memfcn(Base &b) { b = *this; }

};


#endif
