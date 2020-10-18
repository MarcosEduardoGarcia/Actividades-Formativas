#ifndef HEAPS_H
#define HEAPS_H

#include <iostream>
#include <string>
#include <sstream>

using namespace std;

template <class T>
class Heap{
private:
  T *arreglo;
  unsigned int tam;
  unsigned int size_heap;
  void intercambia(unsigned int, unsigned int);
  unsigned int padre(unsigned int);
  unsigned int hijo_izq(unsigned int);
  unsigned int hijo_der(unsigned int);
  void heapify_push(unsigned int);
  void heapify_pop(unsigned int);

public:
  Heap(unsigned int);
  void push(T);
  void pop();
  unsigned int top();
  bool empty();
  unsigned int size();
  string toString() const;
};

//Constructor
template <class T>
Heap<T>::Heap(unsigned int tam){
  this->tam = tam;
  arreglo = new T[tam];
  size_heap = 0;
}

template <class T>
void Heap<T>::intercambia(unsigned int i, unsigned int j) {
	T aux = arreglo[i];
	arreglo[i] = arreglo[j];
	arreglo[j] = aux;
}

//size_heap del padre
template <class T>
unsigned int Heap<T>::padre(unsigned int pos) {
	return (pos - 1) / 2;
}

//size_heap del hijo izquierdo
template <class T>
unsigned int Heap<T>::hijo_izq(unsigned int pos) {
	return ((2 * pos) + 1);
}

//size_heap del hijo derecho
template <class T>
unsigned int Heap<T>::hijo_der(unsigned int pos) {
	return ((2 * pos) + 2);
}

template <class T>
void Heap<T>::heapify_pop(unsigned int posicion){
  unsigned int izquierdo =  hijo_izq(posicion);
  unsigned int derecho = hijo_der(posicion);

  unsigned int peque = posicion;

  if (izquierdo <= size_heap && arreglo[izquierdo] < arreglo[peque]){
    peque = izquierdo;
  }
  if (derecho <= size_heap && arreglo[derecho] < arreglo[peque]){
    peque = derecho;
  }
  if (peque != posicion){
    intercambia(posicion, peque);
    heapify_pop(peque);
  }
}

template <class T>
void Heap<T>::heapify_push(unsigned int posicion){

  if (posicion && arreglo[posicion] < arreglo[padre(posicion)]){
    intercambia(posicion,padre(posicion));
    heapify_push(padre(posicion));
  }
}

template <class T>
void Heap<T>::push(T valor){

  unsigned int pos = size_heap;
  size_heap++;
  arreglo[pos] = valor;
  heapify_push(pos);
}

template <class T>
void Heap<T>::pop(){

  arreglo[0] = arreglo[--size_heap];
  heapify_pop(0);
}

template <class T>
bool Heap<T>::empty() {
	return (size_heap == 0);
}

template <class T>
unsigned int Heap<T>::size(){
  return (size_heap);
}

template <class T>
unsigned int Heap<T>::top(){
  return arreglo[0];
}


template <class T>
string Heap<T>::toString() const {
	stringstream aux;
	aux << "[";	for (unsigned int i = 0; i < size_heap; i++) {
		if (i != 0) {
			aux << " ";
		} aux << arreglo[i];
	} aux << "]";
	return aux.str();
}


#endif
