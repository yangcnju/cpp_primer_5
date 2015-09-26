#include "Folder.h"

void Folder::addMsg(Message *m)
{
	msgs.insert(m);
}

void Folder::remMsg(Message *m)
{
	msgs.erase(m);
}

// Copy Control
Folder::Folder(const Folder &f):
	msgs(f.msgs) {}

Folder::~Folder()
{
	msgs.clear();
}

Folder& Folder::operator=(const Folder &f)
{
	msgs = f.msgs;
	return *this;
}
