#ifndef LIST_H
#define LIST_H

#include <string>
#include <sstream>
#include <iostream>
using namespace std;
//Hacer funcionar la clase amiga
template <class T> class List;

/**********Class nodo**********/
template <class T>
class Nodo{
private:
  //Atributos
	T valor;
	Nodo<T> *Flecha;
	//Constructores
	Nodo(T);
	Nodo(T, Nodo<T>*);
	//Clase amiga
	friend class List<T>;
};

//Desarrollo de constructores
template <class T>
Nodo<T>::Nodo(T valor){
	this->valor = valor;
	Flecha = 0;
}
template <class T>
Nodo<T>::Nodo(T valor, Nodo* Flecha){
	this->valor = valor;
	this->Flecha = Flecha;
}

/***********Clase List ***********/
template <class T>
class List{
	private:
		Nodo<T> *head;
		int size;
	public:
		List();
		//~List();
		void add(T);
		int find(int);
		void update(int, int);
		void remove(int);
		std::string toString() const;
};
//Constructor
template <class T>
List<T>::List() : head(0), size(0){}

//Funcion Add
template <class T>
void List<T>::add(T valor){

	Nodo<T> *NewNodo, *p;

	NewNodo = new Nodo<T>(valor);
	p = head;

	if(head ==0){
		NewNodo->Flecha = head;
		head = NewNodo;
		size++;
		return;
	}


	while (p->Flecha != 0){
		p = p->Flecha;
	}

	NewNodo->Flecha = 0;
	p->Flecha = NewNodo;
	size++;
}

template <class T>
int List<T>::find(int valor){

	Nodo <T> *p;
	int indice = 0;

	p = head;
	while( valor != p->valor ){
		if(indice < size-1){
			p = p->Flecha;
			indice++;
		}
		else{
			return -1;
		}
	}
	return indice;
}

//Agregar un metodo toString a su clase.h
template <class T>
std::string List<T>::toString() const {
	std::stringstream aux;
	Nodo<T> *p;
	p = head;
	aux << "[";
	while (p != 0) {
		aux << p->valor;
		if (p->Flecha != 0) {
			aux << ", ";
		}
		p = p->Flecha;
	}
	aux << "]";
	return aux.str();
}

template <class T>
void List<T> :: update(int indice,int valor){
	Nodo<T> *p;
	int pos = 0;
	p = head;
	while(pos != indice){
		p = p->Flecha;
		pos++;
	}
	p->valor = valor;
}

template <class T>
void List<T> :: remove(int indice){

	Nodo<T> *p, *q;
	int pos = 0;
	p = head;
	q=0;
	if(indice == 0){
		head = p->Flecha;
		delete p;
		size--;
		return;
	}

	while (pos != indice){
		q = p ;
		p = p->Flecha;
		pos ++;
	}
	q->Flecha = p->Flecha;
	size--;
	delete p;
}

#endif //LIST_H
