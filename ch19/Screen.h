// Page 836 for pointer to data members

#include <string>

class Screen {
public:
	Screen(int h, int w, const std::string &s = "") 
		: contents(s), cursor(0), height(h), width(w) {}
	~Screen() {}

	typedef std::string::size_type pos;
	char get_cursor() const { return contents[cursor]; }
	char get() const;
	char get(pos ht, pos wd) const;

	// page 837
	static const std::string Screen::*data()
	{ return &Screen::contents; }

	const pos Screen::*current();
	
private:
	std::string contents;
	pos cursor;
	pos height, width;
};	// class Screen
