#ifndef _BinaryQuery_h
#define _BinaryQuery_h

#include "Query_base.h"
#include <string>
#include <iostream>

class BinaryQuery: public Query_base {
protected:
	BinaryQuery(const Query &l, const Query &r, 
							const std::string &s):
		lhs(l), rhs(r), opSym(s) { std::cout << "BinaryQuery(l,r,s)\t"; }
	// abstract class: BinaryQuery doesn't define eval()
	std::string rep() const { return "(" + lhs.rep() + " "
                                       + opSym + " "
																			 + rhs.rep() + ")"; }
	Query lhs, rhs;
	std::string opSym;
};

#endif
