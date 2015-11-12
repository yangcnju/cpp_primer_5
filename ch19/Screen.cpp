#ifndef _Screen_h
#define _Screen_h

#include "Screen.h"
#include <string>
#include <stdexcept>

using std::string;

char Screen::get() const
{
  pos sz = contents.size();
	char content;
  if(cursor<sz){
		content = contents[cursor];
	}
	else{
		throw std::out_of_range("cursor at the end.");
	}	
	return content;
}

char Screen::get(pos ht, pos wd) const
{
	if(ht > height - 1)
		throw std::out_of_range("height out of range.");
	else if(wd > width - 1)
		throw std::out_of_range("width out of range.");
	pos p = ht * width + wd;
	return contents[p];
}

// exercise 19.12.cc
const string::size_type Screen::* Screen::current()
{ return &Screen::cursor; }

#endif
