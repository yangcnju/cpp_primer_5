#ifndef _Folder_h
#define _Folder_h

#include <set>

class Message;

class Folder{
public:
	Folder() = default;
	Folder(const Folder&);
	Folder& operator=(const Folder&);
	~Folder();

	void addMsg(Message*);
	void remMsg(Message*);
private:
	std::set<Message*> msgs;
};

#endif
