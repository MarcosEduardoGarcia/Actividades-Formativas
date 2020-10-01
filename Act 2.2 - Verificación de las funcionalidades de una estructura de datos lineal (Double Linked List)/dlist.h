#ifndef DLIST_H
#define  DLIST_H


#include <iostream>
#include <sstream>
#include <string>

using namespace std;

template <class T> class DList;

/*********Clase NodoDoble*********/

template <class T>
class NodoDoble{
private:
  NodoDoble(T);


  T valor;
  NodoDoble<T> *Flecha_Atras;
  NodoDoble<T> *Flecha_Adelante;

  friend class DList<T>;
};
//Constructores

template<class T>
NodoDoble<T>::NodoDoble(T valor){
  this->valor = valor;
  Flecha_Atras = 0;
  Flecha_Adelante = 0;
}

/***********Clase DList*****************/

template<class T>
class DList{
private:
  NodoDoble<T> *head;
  NodoDoble<T> *tail;
  int size;
public:
  DList();

  void add(T);
  int find(int);
  void update(int, int);
  void remove(int);
  std::string toStringForward() const;
	std::string toStringBackward() const;
};

//Constructor
template <class T>
DList<T> :: DList() : head(0),tail(0),size(0){};

//Funcion add

template <class T>
void DList<T>::add(T valor){

  NodoDoble<T> *NewNodo, *p;

  NewNodo = new NodoDoble<T>(valor);

  p = head;

  if (size == 0){
    head = NewNodo;
    tail = NewNodo;
  }
  else{
    tail->Flecha_Adelante = NewNodo;
    NewNodo->Flecha_Atras =  tail;
    tail =  NewNodo;
  }
  size++;
}

template <class T>
int DList<T>::find(int valor){
  NodoDoble <T> *p;
  int indice = 0;

  p = head;
  while( valor != p->valor ){
    if(indice < size-1){
      p = p->Flecha_Adelante;
      indice++;
    }
    else{
      return -1;
    }
  }
  return indice;
}

template <class T>
void DList<T> :: update(int indice,int valor){
	NodoDoble<T> *p;
	int pos = 0;
	p = head;
	while(pos != indice){
		p = p->Flecha_Adelante;
		pos++;
	}
	p->valor = valor;
}

template <class T>
void DList<T> :: remove(int indice){

  NodoDoble<T> *p;
  p = head;
  int pos = 0;
  if(indice == 0){
    head = p->Flecha_Adelante;
    p->Flecha_Adelante->Flecha_Atras = 0;
    delete p;
    size --;
    return;
  }
  if(indice == size-1){
    p = tail;
    tail = p->Flecha_Atras;
    p->Flecha_Atras->Flecha_Adelante=0;
    delete p;
    size--;
    return;
  }
  while (pos != indice){
    p = p->Flecha_Adelante;
    pos++;
  }
  p->Flecha_Atras->Flecha_Adelante = p->Flecha_Adelante;
  p->Flecha_Adelante->Flecha_Atras = p->Flecha_Atras;
  delete p;
  size--;
}

// Incluye estos funciones en tu dlist.h para poder imprimir tus respuestas
// en formatos compatibles con el main
template <class T>
std::string DList<T>::toStringForward() const {
	std::stringstream aux;
	NodoDoble<T> *p;
	p = head;
	aux << "[";
	while (p != 0) {
		aux << p->valor;
		if (p->Flecha_Adelante != 0){
			aux << ", ";
		}
		p = p->Flecha_Adelante;
  }
	aux << "]";
	return aux.str();
}

template <class T>
std::string DList<T>::toStringBackward() const {
	std::stringstream aux;
	NodoDoble<T> *p;
	p = tail;
	aux << "[";
	while (p != 0) {
		aux << p->valor;
		if (p->Flecha_Atras != 0) {
			aux << ", ";
		}
		p = p->Flecha_Atras;
	}
	aux << "]";
	return aux.str();
}

#endif
