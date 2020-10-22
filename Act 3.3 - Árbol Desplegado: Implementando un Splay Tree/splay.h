#ifndef SPLAY_H_
#define SPLAY_H_

#include <sstream>
#include <iostream>

template <class T> class SplayTree;

using namespace std;

template <class T>
class Nodo {

private:

  T valor;
  Nodo *izquierda, *derecha, *padre;

  Nodo<T>* succesor();
  Nodo<T>* rot_derecha(Nodo<T>*);
  Nodo<T>* rot_izquierda(Nodo<T>*);

public:

  Nodo (T);
  Nodo (T, Nodo<T>*, Nodo<T>*, Nodo<T>*);
  Nodo<T>* add(T);
  Nodo<T>* find(T);
  Nodo<T>* remove(T);
  void removeChilds();
  void inorder(stringstream&) const;
  void print_tree(stringstream&) const;
  void preorder(stringstream&) const;
  Nodo<T>* splay(Nodo<T>*, Nodo<T>*);

  friend class SplayTree<T>;
};

template <class T>
Nodo<T>::Nodo(T val) : valor(val), izquierda(0), derecha(0), padre(0) {}

template <class T>
Nodo<T>::Nodo(T val, Nodo<T> *le, Nodo<T> *ri, Nodo<T> *p) : valor(val), izquierda(le), derecha(ri), padre(p) {}

template <class T>
Nodo<T>* Nodo<T>::add(T val) {

  if (val < valor) {

    if (izquierda != 0){
      return izquierda->add(val);
    }
    else {
      izquierda = new Nodo<T>(val);
      izquierda->padre = this;
      return izquierda;
    }
  }

  else {

    if (derecha != 0) {
      return derecha->add(val);
    }
    else {
      derecha = new Nodo<T>(val);
      derecha->padre = this;
      return derecha;
    }
  }
}

template <class T>
Nodo<T>* Nodo<T>::succesor(){
	Nodo<T> *le, *ri;

	le = izquierda;
	ri = derecha;

	if (derecha == 0){
		if (izquierda != 0){
			izquierda = 0;
		}
	if(le)
		le->padre = 0;
	return le;
	}

	if (derecha->izquierda == 0){
		derecha = derecha->derecha;
		if(derecha)
			derecha->padre = padre;
		if(ri){
			ri->derecha = 0;
			ri->padre = 0;
		}
		return ri;
	}

	Nodo<T> *p, *c;
	p = derecha;
	c = derecha->izquierda;
	while(c->izquierda != 0){
		p = c;
		c = c->izquierda;
	}
	p->izquierda = c->derecha;
	if(p->izquierda != 0)
		p->izquierda->padre = p;
	c->derecha = 0;
	return c;
}

template <class T>
Nodo<T>* Nodo<T>::remove(T val) {
Nodo<T> *succ, *old;
if (val < valor) {
  if (izquierda != 0) {
    if (izquierda->valor == val) {
      old = izquierda;
      succ = izquierda->succesor();
      if (succ != 0) {
        succ->izquierda = old->izquierda;
        succ->derecha = old->derecha;
        succ->padre = old->padre;
        if (succ->izquierda)
          succ->izquierda->padre = succ;
        if (succ->derecha)
          succ->derecha->padre = succ;
      }
      izquierda = succ;
      delete old;
      return this;
    } else {
      return izquierda->remove(val);
    }
  }
} else if (val > valor) {
  if (derecha != 0) {
    if (derecha->valor == val) {
      old = derecha;
      succ = derecha->succesor();
      if (succ != 0) {
        succ->izquierda = old->izquierda;
        succ->derecha = old->derecha;
        succ->padre = old->padre;
        if (succ->izquierda)
          succ->izquierda->padre = succ;
        if (succ->derecha)
          succ->derecha->padre = succ;
      }
      derecha = succ;
      delete old;
      return this;
  } else {
    return derecha->remove(val);
      }
    }
  }
  return 0;
}

template <class T>
Nodo<T>* Nodo<T>::rot_derecha(Nodo<T>* x){
  Nodo<T> *y = x->izquierda;
  x->izquierda = y->derecha;
  if(y->derecha)
    y->derecha->padre = x;
  y->derecha = x;
  // enlace de y con el padre de x
  y->padre = x->padre;
  x->padre = y;
  // enlace del padre de xx a y
  if (y->padre){
    if (y->padre->izquierda && y->padre->izquierda->valor == x->valor)
      y->padre->izquierda = y;
    else
      y->padre->derecha = y;
  }
  return y;
}

template <class T>
Nodo<T>* Nodo<T>::rot_izquierda(Nodo<T>* x){
  Nodo<T> *y = x->derecha;
  x->derecha = y->izquierda;
  if(y->izquierda)
    y->izquierda->padre = x;
  y->izquierda = x;
  // enlace de y con el padre de x
  y->padre = x->padre;
  x->padre = y;
  // enlace del padre de xx a y
  if (y->padre) {
    if (y->padre->izquierda && y->padre->izquierda->valor == x->valor)
      y->padre->izquierda = y;
    else
      y->padre->derecha = y;
  }
  return y;
}

template <class T>
Nodo<T>* Nodo<T>::find(T val) {
  if (val == valor){
    return this;
  } else if (val < valor) {
    if (izquierda != 0)
    return izquierda->find(val);
  else
    return this;
  } else if (val > valor) {
    if (derecha != 0)
      return derecha->find(val);
    else
      return this;
  }
  return 0;
}

template <class T>
Nodo<T>* Nodo<T>::splay(Nodo<T>* root,Nodo<T>* x) {
  while (x->padre != 0){

    if(x->padre->valor == root->valor) {
      if(x->padre->izquierda && x->padre->izquierda->valor == x->valor){
        rot_derecha(x->padre);
      } else {
        rot_izquierda(x->padre);
      }
	} else{
        Nodo<T>*p = x->padre; //padre
        Nodo<T>*g = p->padre; //abuelo

        if(p->izquierda && g->izquierda &&
		x->valor == p->izquierda->valor && p->valor == g->izquierda->valor){
		  rot_derecha(g);
          rot_derecha(p);
        } else if (p->derecha && g->derecha &&
		x->valor == p->derecha->valor && p->valor == g->derecha->valor){
		  rot_izquierda(g);
          rot_izquierda(p);
        } else if (p->izquierda && g-> derecha &&
		x->valor == p->izquierda->valor && p->valor == g->derecha->valor){
		  rot_derecha(p);
          rot_izquierda(g);
        } else {
		  rot_izquierda(p);
          rot_derecha(g);
        }
      }
    }
    return x;
}


template <class T>
void Nodo<T>::inorder(stringstream &aux) const {
  if (izquierda != 0) {
    izquierda->inorder(aux);
  }
  if (aux.tellp() != 1) {
    aux << " ";
  }
  aux << valor;
  if (derecha != 0) {
    derecha->inorder(aux);
  }
}
template <class T>
void Nodo<T>::print_tree(stringstream &aux) const {
  if (padre != 0) {
    aux << "\n Nodo " << valor;
    aux << " padre " << padre->valor;
  } else
    aux << "\n root " << valor;
  if (izquierda != 0)
    aux << " izquierda " << izquierda->valor;
  if (derecha != 0)
    aux << " derecha " << derecha->valor;
  aux << "\n";

  if (izquierda != 0) {
    izquierda->print_tree(aux);
  }
  if (derecha != 0) {
    derecha->print_tree(aux);
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
class SplayTree {

private:
  Nodo<T> *root;
  int cont;
public:
  SplayTree();
  bool empty() const;
  void add(T);
  bool find (T);
  void remove (T);
  string inorder() const;
  string print_tree() const;
  string preorder() const;
  int size();
};

template <class T>
SplayTree<T>::SplayTree() : root(0) {}

template <class T>
bool SplayTree<T>::empty() const {
  return (root == 0);
}

template <class T>
void SplayTree<T>::add(T val) {
  cont ++;
  if ( root != 0) {
    Nodo<T>* added = root->add(val);
    root = root->splay(root,added);
  }
  else {
    root = new Nodo<T>(val);
  }
}

template <class T>
void SplayTree<T>::remove(T val) {
  cont--;
  if (root != 0) {
    if (val == root->valor) {
      Nodo<T> *succ = root->succesor();
      if (succ != 0) {
        succ->izquierda = root->izquierda;
        succ->derecha = root->derecha;
        succ->padre = 0;
        if (succ->izquierda)
          succ->izquierda->padre = succ;
        if (succ->derecha)
          succ->derecha->padre = succ;
      }
      delete root;
      root = succ;
    } else {
      Nodo<T>* p = root->remove(val);
      root = root->splay(root,p);
    }
  }
}

template <class T>
bool SplayTree<T>::find(T val) {
  if (root != 0) {
    Nodo<T>* found = root->find(val);
    root = root->splay(root,found);
    return (root->valor == val);
  } else {
    return false;
  }
}

template <class T>
string SplayTree<T>::inorder() const {
  stringstream aux;

  aux << "[";
  if (!empty()) {
    root->inorder(aux);
  }
  aux << "]";
  return aux.str();
}

template <class T>
string SplayTree<T>::print_tree() const {
  stringstream aux;

  aux << "\n ================================ ";
  if (!empty()) {
    root->print_tree(aux);
  }
  aux << " ================================== \n";
  return aux.str();
}

template <class T>
string SplayTree<T>::preorder() const {
  stringstream aux;

  aux << "[";
  if (!empty()) {
    root->preorder(aux);
  }
  aux << "]";
  return aux.str();
}

template <class T>
int SplayTree<T>::size(){
	return cont;
}

#endif
