#ifndef _Screen_h
#define _Screen_h

#include <string>
#include <iostream>

template <unsigned, unsigned> class Screen;

template <unsigned H, unsigned W>
std::ostream& operator<<(std::ostream &os, const Screen<H,W> &s)
{
	os << s.height() << " "
		 << s.width() << " "
		 << s.show() << std::endl;
	return os;
}

template <unsigned H, unsigned W>
std::istream& operator>>(std::istream& is, Screen<H,W> &s)
{
	std::string temp;
	is >> temp;
	s.info = temp;
	return is;
}

template <unsigned H, unsigned W>
class Screen {
	friend std::ostream& operator<< <H,W>(std::ostream&, const Screen&);
	friend std::istream& operator>> <H,W>(std::istream&, Screen&);
public:
	Screen(const std::string &s = ""): h(H), w(W), info(s) {}
	Screen(const Screen<H,W>& s): h(s.h), w(s.w), info(s.info) {}
	Screen& operator=(const Screen<H,W>& s)
	{ h = s.h; w = s.w; info = s.info; return *this; }

	unsigned height() const { return h; }
	unsigned width() const { return w; }
	std::string show() const { return info; }
private:
	unsigned h;
	unsigned w;
	std::string info;
};	// class Screen

#endif
