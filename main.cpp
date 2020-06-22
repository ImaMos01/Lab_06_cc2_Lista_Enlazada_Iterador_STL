#include "linkedlist.h"
#include "linkedlist.cpp"
#include <list>

void Showlist(std::list<int> number){
	std::list<int>::iterator pos;
	pos = number.begin();
	while(pos!=number.end()){
		std::cout<<*pos<<"\t";
		pos++;
	}
	std::cout<<"\n";
}

int main() {
	
	//lista enlazada
	LinkedList<char>* lis = new LinkedList<char>;
	char a;
	std::cout << "press: 'a' to exit\n";
	while (a != 'a') {
		std::cout << "enter: ";
		std::cin >> a;
		lis->Insert(a);
	}
	lis->print();
	std::cout << "\n";

	std::cout << "what number do you want to remove: \n";
	std::cin >> a;
	std::cout << "\n";

	lis->Remove(a);
	lis->print();

	lis->Push_back('c');
	lis->Push_front('a');
	lis->print();

	std::cout << "copy\n";
	LinkedList<char>* lis2 = lis;
	lis2->print();
	
	/*
	//con iterador
	LinkedList<int>* lista = new LinkedList<int>;
	lista->insert(lista->end(), 2);
	lista->insert(lista->end(), 4);
	lista->insert(lista->end(), 5);

	auto iter = lista->begin();
	iter = lista->insert(iter, 1); // Insert 1 before 2
	iter++; // Points to 2
	lista->insert(iter++, 3); // Inserta 3 antes 2, advance to 4
	iter++; // apunta a 5
	lista->insert(iter, 10); // Inserta 10 antes 5

	iter = lista->begin();
	iter++; // apunta a 3
	lista->erase(iter); //elimina 3

	for (auto itr = lista->begin(); itr != lista->end(); itr++)
		std::cout << *itr << "\n";
	*/
	
	//con la libreria stl
	std::list<int> numbers;
	numbers.push_back(2);
	numbers.push_back(5);
	numbers.push_back(8);
	numbers.push_back(9);
	Showlist(numbers);
	std::cout<<"tamano: "<<numbers.size()<<"\n";
	
	numbers.pop_back();
	Showlist(numbers);
	std::cout<<"tamano: "<<numbers.size()<<"\n";
	
	return 0;
}