#ifndef _String_h
#define _String_h

#include <memory>
#include <utility>
#include <initializer_list>

class String{
	friend String& operator+(const String&, const String&);
public:
	String():
		elements(nullptr), first_free(nullptr), cap(nullptr) {}
	String(const String&);
	String(String&&) noexcept;
	String& operator=(const String&);
	String& operator=(String&&) noexcept;
	String(const std::initializer_list<char> &il);
	~String();

	size_t size() const { return first_free - elements; }
	size_t capacity() const { return cap - elements; }
	char *begin() const { return elements; }
	char *end() const { return first_free; }
private:
	static std::allocator<char> alloc;	// needs to define in .cc
	void chk_n_alloc()
	{ if(size()==capacity()) reallocate(); }
	std::pair<char*, char*> alloc_n_copy
		(const char*, const char*);

	void free();
	void reallocate();
	char *elements;
	char *first_free;
	char *cap;
};

#endif
