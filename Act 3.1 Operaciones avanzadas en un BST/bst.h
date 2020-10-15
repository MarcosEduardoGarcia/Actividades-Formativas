#ifndef BST_H_
#define BST_H_

#include <string>
#include <sstream>
#include <iostream>
using namespace std;

template <class T> class BST;
template <class T>
class Nodo {
private:
	T valor;
	Nodo *izquierda, *derecha;
public:
	Nodo(T);
	Nodo(T, Nodo<T>*, Nodo<T>*);
	void add(T);
	bool find(T);
	int height() const;
	int whatlevelamI(T);
	void inorder(stringstream&) const;
	void preorder(stringstream&) const;
	void postorder(stringstream&) const;
	void RecorreNiveles(stringstream&) const;
	void DaNiveles(stringstream&,int) const;
	bool ancestors(stringstream &aux,T val) const;

	friend class BST<T>;
};

template <class T>
Nodo<T>::Nodo(T val) : valor(val), izquierda(0), derecha(0) {}

template <class T>
Nodo<T>::Nodo(T val, Nodo<T> *le, Nodo<T> *ri)
	: valor(val), izquierda(le), derecha(ri) {}


template <class T>
void Nodo<T>::add(T val) {
	if (val < valor) {
		//recursividad hacia el lado izquierdo
		if (izquierda != 0) {
			izquierda->add(val);
		} else {
			izquierda = new Nodo<T>(val);
		}
	}
	else{
		//Recursividad hacia el lado derecho
		if (derecha != 0) {
			derecha->add(val);
		} else {
			derecha = new Nodo<T>(val);
		}
	}
}

template <class T>
bool Nodo<T>::find(T val) {
	if (val == valor) {
		return true;
	}
	else if (val < valor) {
		return (izquierda != 0 && izquierda->find(val));
	}
	else if (val > valor) {
		return (derecha != 0 && derecha->find(val));
	}
	return false;
}

template <class T>
int Nodo<T>::height() const{

	int height_derecha = 0;
	int height_izquierda = 0;

	if (izquierda != 0){
		height_izquierda = izquierda->height() + 1;
	}
	if (derecha != 0){
		height_derecha = derecha->height() + 1;
	}
	if (height_derecha == 0 && height_izquierda == 0){
		return 1;
	}
	if (height_derecha > height_izquierda){
		return height_derecha;
	}
	else{
		return height_izquierda;
	}
}

template <class T>
int Nodo<T>::whatlevelamI(T val){
	if(val == valor){
		return 1;
	}
	else if (val<valor){
		if (izquierda !=0){
			return izquierda->whatlevelamI(val)+1;
		}
	}
	else if (val>valor){
		if (derecha != 0){
			return derecha->whatlevelamI(val)+1;
		}
	}
	return -1;
}


template <class T>
void Nodo<T>::inorder(stringstream &aux) const {
	if (izquierda != 0) {
		izquierda->inorder(aux);
	}
	//dejar espacio
	if (aux.tellp() != 1) {
		aux << " ";
	}
	aux << valor;
	if (derecha != 0) {
		derecha->inorder(aux);
	}
}

template <class T>
void Nodo<T>::preorder(stringstream &aux) const {
	aux << valor;
	if (izquierda != 0) {
		aux << " ";
		izquierda->preorder(aux);
	}
	if (derecha != 0) {
		aux << " ";
		derecha->preorder(aux);
	}
}

template <class T>
void Nodo<T>::postorder(stringstream &aux) const {

	if(izquierda != 0){
		izquierda->postorder(aux);
	}
	if (derecha != 0){
		derecha->postorder(aux);
	}
	if (aux.tellp() != 1){
		aux << " ";
	}
	aux << valor;
}

template <class T>
void Nodo<T>::DaNiveles(stringstream &aux, int level) const {

	if(level >= 0){
		if (aux.tellp() != 1) {
			aux << " ";
		}
		aux << valor;
	}
	if (izquierda != 0) {
		izquierda->DaNiveles(aux, level -1);
	}
	if (derecha != 0) {
		derecha->DaNiveles(aux, level -1);
	}
}

template <class T>
void Nodo<T>::RecorreNiveles(stringstream &aux) const {
	int level = height();

	DaNiveles(aux, level);
}

template <class T>
bool Nodo<T>::ancestors(stringstream &aux,T val) const{

	if (val == valor) {
	  return true;
	} else if (val < valor) {
		if (aux.tellp() != 1) {
			aux << " ";
		}
		aux << valor;
		return (izquierda != 0 && izquierda->ancestors(aux,val));
	} else if (val > valor) {
		if (aux.tellp() != 1) {
			aux << " ";
		}
		aux << valor;
		return (derecha != 0 && derecha->ancestors(aux,val));
	}
	return false;
}

/********Clase BST***********/
template <class T>
class BST {
private:
	Nodo<T> *root;
public:
	BST();
	bool empty() const;
	void add(T);
	bool find(T) const;
	int height();
	string inorder() const;
	string preorder() const;
	string postorder() const;
	string RecorreNiveles() const;
	string visit();
	int whatlevelamI(T) const;
	string ancestors(T val) const;
};

template <class T>
BST<T>::BST() : root(0) {}

template <class T>
bool BST<T>::empty() const {
	return (root == 0);
}

template<class T>
void BST<T>::add(T val) {
	if (root != 0) {
		if (!root->find(val)) {
			root->add(val);
		}
	}
	else {
		root = new Nodo<T>(val);
	}
}

template <class T>
bool BST<T>::find(T val) const {
	if (root != 0) {
		return root->find(val);
	}
	else {
		return false;
	}
}

template <class T>
int BST<T>::height(){
	return root->height();
}

template <class T>
string BST<T>::visit() {
	stringstream aux;
	aux << preorder() << "\n";
	aux << inorder() << "\n";
	aux << postorder() << "\n";
	aux << RecorreNiveles();
	return aux.str();
}


template <class T>
string BST<T>::inorder() const {
	stringstream aux;

	aux << "[";
	if (!empty()) {
		root->inorder(aux);
	}
	aux << "]";
	return aux.str();
}

template <class T>
string BST<T>::preorder() const {
	stringstream aux;

	aux << "[";
	if (!empty()) {
		root->preorder(aux);
	}
	aux << "]";
	return aux.str();
}

template <class T>
string BST<T>::postorder() const {
	stringstream aux;

	aux << "[";
	if (!empty()) {
	root->postorder(aux);
	}
	aux << "]";
	return aux.str();
}

template <class T>
string BST<T>::RecorreNiveles() const {
	stringstream aux;

	aux << "[";
	if (!empty()) {
		root->RecorreNiveles(aux);
	}
	aux << "]";
	return aux.str();
}

template <class T>
int BST<T>::whatlevelamI(T val) const {
	if (root != 0) {
		return root->whatlevelamI(val);
	}
	else {
		return -1;
	}
}

template <class T>
string BST<T>::ancestors(T val) const {
	stringstream aux;
	aux << "[";
	if (!empty()) {
		if(!root->ancestors(aux,val)){
			return "[]";
		}
	}
	aux << "]";
	return aux.str();
}

#endif /* BST_H_ */
