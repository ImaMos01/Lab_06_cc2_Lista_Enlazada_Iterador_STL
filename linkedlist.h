#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include "Node.h"

template<typename U>
class LinkedList {
private:
	int size;
	Node<U>* head;
	Node<U>* tail;
public:
	LinkedList();
	~LinkedList();
	LinkedList(const LinkedList<U>& o);
	//nested class
	class Iterator {
		friend class LinkedList;
		private:
			Node<U>* nodeptr;
			Iterator(Node<U>* newPtr) : nodeptr(newPtr) {}
		public:
			Iterator() : nodeptr(NULL) {}
			bool operator!=(const Iterator& itr) const{ return nodeptr != itr.nodeptr; }
			U& operator*()const{ return nodeptr->next->element; }
			Iterator operator++(int){
				Iterator temp = *this;
				nodeptr = nodeptr->next;
				return temp;
			}
	};//end of the class

	Iterator begin() const { return Iterator(head); }
	Iterator end() const { return Iterator(tail); }

	Iterator insert(Iterator position, const U value) {
		Node<U>* newNode = new Node<U>(value, position.nodeptr->next);
		if (position.nodeptr == tail)
			tail = newNode;
		return position;
	}
	Iterator erase(Iterator position) {
		Node<U>* toDelete = position.nodeptr->next;
		position.nodeptr->next = position.nodeptr->next->next;
		if (toDelete == tail) tail = position.nodeptr;
		delete toDelete;
		return position;
	}

	void Push_front(const U p);
	void Push_back(const U p);

	void print();
	void Insert(const U a);
	void Remove(const U n);
};

#endif

