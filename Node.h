#ifndef NODE_H
#define NODE_H
#include<iostream>

template<typename T>
class Node {
private:
	T element;
	Node<T>* next;
public:
	Node(): next(NULL){}
	Node(const T& item){
		this->element=item; 
		this->next=NULL;
	}
	template<typename U>
	friend class LinkedList; //LinkedList acceda a los valores privados de Node
};

#endif