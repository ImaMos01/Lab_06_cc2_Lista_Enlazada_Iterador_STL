#include "linkedlist.h"
template<typename S>
std::ostream& operator << (std::ostream &o,const Node<S> *p){
    o << "(" << p->element << ")";
    return o;
}

template<typename U>
LinkedList<U>::LinkedList() {
	this->size = 0;
	this->head = NULL;
	this->tail = NULL;
}

template<typename U>
LinkedList<U>::~LinkedList() {
	while (head != NULL) {
		Node<U>* del = head;
		head = head->next;
		delete del;
		size--;
	}
}

template<typename U>
LinkedList<U>::LinkedList(const LinkedList<U>& o) {
	this->size = o->size;
	this->head = o->head;
	this->tail = o->tail;
}


template<typename U>
void LinkedList<U>::Push_front(const U p) {
	Node<U>* newOne = new Node<U>(p);
	if (head == NULL)
		head = newOne;
	else {
		newOne->next = head;
		head = newOne;
	}
	size++;
}


template<typename U>
void LinkedList<U>::Push_back(const U p) {
	Node<U>* newOne = new Node<U>(p);
	Node<U>* aux = head;
	if (head == NULL)
		head = newOne;
	else {
		while (aux != NULL) {
			tail = aux;
			aux = aux->next;
		}
		tail->next = newOne; //agrega en la cola de la lista
	}
}

template<typename U>
void LinkedList<U>::print() {
	Node<U>* print = head; //creamos un puntero nodo para recorrer la lista
	while (print != NULL) {
		std::cout <<print<< "\t";
		print = print->next;
	}
	std::cout << "\n";
}

template <typename U>
void LinkedList<U>::Insert(const U a) {//ordenarlo
	Node<U>* newNode = new Node<U>(a);
	//cuando la lista esta vacia
	if (head == NULL) {
		head = newNode;
	}
	else {
		Node<U>* control = head;
		Node<U>* aux = NULL;
		//recorre hasta encontrar el lugar indicado
		while (control != NULL) {
			if (control->element >= newNode->element)
				break;
			else {
				aux = control;
				control = control->next;
			}
		}
		//inserta en la cabeza
		if (control == head) {
			newNode->next = head;
			head = newNode;
		}
		else {
			//inserta despues de la cabezera
			newNode->next = control;
			aux->next = newNode;
		}
	}
	size++;
}

template<typename U>
void LinkedList<U>::Remove(const U n) {
	//lista vacia
	if (head == NULL) {
		std::cout << "Node cannot be deleted from an empty list\n";
	}
	else {
		Node<U>* control = head;
		Node<U>* aux = NULL;
		//recorre hasta encontrar el nodo para eliminarlo
		while (control != NULL) {
			if (control->element == n)
				break;
			else {
				aux = control;
				control = control->next;
			}
		}
		//numero ingrersado no se encuentra en la lista
		if (control == NULL) {
			std::cout << "the value: " << n << " is not found\n";
		}
		else {
			//eliminar en la cabezera
			if (head == control)
				head = head->next;
			//elimina desde la cola de la lista
			else
				aux->next = control->next;
			delete control;
			size--;
		}
	}

}
