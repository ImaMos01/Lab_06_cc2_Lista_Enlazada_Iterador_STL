#ifndef NODE_H
#define NODE_H
#include<iostream>

template<typename T>
class Node {
private:
	T element;
	Node<T>* next;
public:
	Node(const T& item, Node<T> *ptr = NULL){
		this->element=item; 
		this->next=ptr;
	}
	template<typename U>
	friend class LinkedList; //LinkedList acceda a los valores privados de Node
};

#endif