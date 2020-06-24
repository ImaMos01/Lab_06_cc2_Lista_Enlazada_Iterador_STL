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
	std::cout<<"----------------------------------\n";
	//lista enlazada
	std::cout<<"Lista enlazada con templates: \n";
	LinkedList<char>* lis = new LinkedList<char>;
	lis->Insert('a');
	lis->Insert('b');
	lis->Insert('c');
	lis->Insert('d');
	lis->print();
	std::cout << "\n";
	
	std::cout<<"elemina el valor 'c': \n";
	lis->Remove('c');
	lis->print();
	
	std::cout<<"agrega 'z' y 'x':\n";
	lis->Push_back('z');
	lis->Push_front('x');
	lis->print();

	std::cout << "lista copia: \n";
	LinkedList<char>* lis2 = lis;
	lis2->print();
	std::cout<<"\n";
	
	std::cout<<"----------------------------------\n";
	//con iteradores 
	LinkedList<int> iters;
	iters.Push_back(3);
	iters.Push_back(4);
	iters.Push_back(5);
	std::cout << "Recorre la lista enlazada con  un iterador" << "\n"; 
    for ( LinkedList<int>::Iterator iterator = iters.begin(); iterator != iters.end(); iterator++) { 
        std::cout << *iterator << "\t"; 
    }
	std::cout<<"\n";	

	std::cout<<"----------------------------------\n";
	std::cout<<"stl(libreria list)\n";
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