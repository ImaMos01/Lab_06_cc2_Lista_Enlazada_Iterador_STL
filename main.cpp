#include "linkedlist.h"
#include "linkedlist.cpp"
#include <list>
#include <string.h>

class punto{
	private:
		int x;
	public:
		punto(): x(0){}
		punto(int px) : x(px){}
		void setPunto(int px){ x=px;}
		int getPunto(){ return x;}
		friend std::ostream& operator << (std::ostream &o,const punto &p);
};

std::ostream& operator << (std::ostream &o,const punto &p){
    o << "(" << p.x << ")";
    return o;
}

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
	LinkedList<std::string>* lis = new LinkedList<std::string>;
	lis->Insert("juana");
	lis->Insert("maria");
	lis->Insert("pepe");
	lis->Insert("alex");
	lis->print();
	std::cout << "\n";
	
	std::cout<<"elemina 'maria': \n";
	lis->Remove("maria");
	lis->print();
	
	std::cout<<"agrega 'luis' y 'skye':\n";
	lis->Push_back("luis");
	lis->Push_front("skye");
	for ( LinkedList<std::string>::Iterator iterator = lis->begin(); iterator != lis->end(); iterator++) { 
        *iterator; 
    }
	std::cout<<"\n";	

	std::cout << "lista copia: \n";
	LinkedList<std::string>* lis2 = lis;
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
        *iterator; 
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
	
	std::cout<<"----------------------------------\n";
	std::cout<<"con la clase punto:\n";
	punto a(4);
	punto b(7);
	
	LinkedList<punto>* punto_lista = new LinkedList<punto>;
	punto_lista->Push_back(a);
	punto_lista->Push_back(b);
	for ( LinkedList<punto>::Iterator iterator = punto_lista->begin(); iterator != punto_lista->end(); iterator++) { 
        *iterator; 
    }
	
	return 0;
}