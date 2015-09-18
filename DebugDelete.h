#ifndef _DebugDelete_h
#define _DebugDelete_h

#include <iostream>

// function-obj class that calls delete on a given ptr
class DebugDelete {
public:
	DebugDelete(std::ostream &s = std::cerr) : os(s) {}
	template <typename T> void operator()(T *p) const
	{ os << "deleting unique_ptr" << std::endl; delete p; }
private:
	std::ostream &os;
};	// class DebugDelete

#endif
