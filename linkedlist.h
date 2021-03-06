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

	void Push_front(const U p);
	void Push_back(const U p);

	void print();
	void Insert(const U a);
	void Remove(const U n);
	
	class Iterator{
		private:
			const Node<U>* Current;
		public:
			Iterator() : Current(head){}
			Iterator(const Node<U>* pNode): Current(pNode){}
			Iterator& operator=(Node<U>* pNode){
				this->Current=pNode;
				return *this;
			} 
  
			Iterator operator++(int){ 
				Iterator iterator = *this;
				Current = Current->next;				
				return iterator; 
			} 
  
			bool operator!=(const Iterator& iterator){ 
				return Current != iterator.Current; 
			} 
  
			void operator*(){ 
				std::cout<<Current<<"\t"; 
			} 
	};
	Iterator begin(){ return Iterator(head);}
	Iterator end() {return Iterator(NULL);}
	
};

#endif

