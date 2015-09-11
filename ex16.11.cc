// correct the List definition.
#include <iostream>

template <typename elemType> class ListItem;
template <typename elemType> class List {
public:
	List<elemType>();
	List<elemType>(const List<elemType> &);
	List<elemType>& operator=(const List<elemType> &);
	~List();

	// need typename for ListItem, otherwise not a real type
	void insert(ListItem<elemType> *ptr, elemType value);
private:
	ListItem<elemType> *front, *end;
};

// Implementation for List
// type definition not completed. Need to handle memory properly:
// pop() or pop_front() needed for destructor.
template <typename elemType>
List<elemType>::List<elemType>()
	: front(nullptr), end(nullptr) {}

template <typename elemType>
List<elemType>::List<elemType>(const List<elemType> &rhs):
	front(rhs.front), end(rhs.end) {}		// need to be carefull when deleting ptrs

template <typename elemType>
List<elemType>& List<elemType>::operator=(const List<elemType> &rhs)
{
	front = rhs.front;
	end = rhs.end;
	return *this;
}

template <typename elemType>
void List<elemType>::insert(ListItem<elemType> *ptr, elemType value);
{
	List<elemType> *inserted = new ListItem<elemType>(value);
	inserted.next = ptr;
	inserted.prev = ptr->prev;
	ptr->prev = inserted;
}

template <typename elemType>
List<elemType>::~List()
{
	while(front!=end){
		auto temp = front;
		front = front->next;
		delete temp;
	}
	delete front;
	front = end = nullptr;
}

// type definition not completed. Need to handle memory properly:
template <typename elemType> class ListItem {
	friend class List<elemType>;
public:
	ListItem<elemType>(): e(elemType()) {}
	ListItem<elemType>(const elemType &v) : e(v) {}
	ListItem<elemType>(const ListItem<elemType> &rhs):
		e(rhs.e) {}
	ListItem<elemType>(ListItem<elemType> &&rhs):
		e(std::move(rhs.e)) {}

	ListItem<elemType>& operator=(const ListItem<elemType> &rhs) { e = rhs.e; }
	~ListItem()  {}

	elemType elem() const { return e; }
private:
	elemType e;
	ListItem<elemType> *prev;
	ListItem<elemType> *next;
}
