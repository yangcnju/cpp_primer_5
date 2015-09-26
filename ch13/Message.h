#ifndef _Message_h
#define _Message_h

#include <string>
#include <set>
#include "Folder.h"

class Message{
	friend void swap(Message&, Message&);
	friend class Folder;
public:
	explicit Message(const std::string &str = ""):
		contents(str) {}

	Message(const Message&);
	Message& operator=(const Message&);
	~Message();

	void save(Folder&);
	void remove(Folder&);
	std::string show() const;
private:
	std::string contents;
	std::set<Folder*> folders;
	void add_to_Folders(const Message&);
	void remove_from_Folders();
};

#endif
