#ifndef SORTS_H_
#define SORTS_H_
#include <iostream>
#include <vector>
using namespace std;

//Plantilla de clase
template <class T>
class Sorts {

private:
	void swap(vector<T>&, int, int);
	void mergeArray(vector<T>&, vector<T>&, int, int, int);
	void mergeSplit(vector<T>&, vector<T>&, int, int);
	void copyarray(vector<T>&, vector<T>&, int, int);
public:
	void ordenaBurbuja(vector<T>&);
	void ordenaSeleccion(vector<T>&);
	void ordenaMerge(vector<T>&);
  int busqSecuencial(const vector<T>&, int);
  int busqBinaria(const vector<T>&, int);

};

//Swapeo de datos en el arreglo
template <typename T>
void Sorts<T>::swap(vector<T> &vector, int i, int j) {
	T aux = vector[i];
	vector[i] = vector[j];
	vector[j] = aux;
}

//Ordenamiento burbuja
template <typename T>
void Sorts<T>::ordenaBurbuja(vector<T>&vector){

	int i=0;
	bool ordenado = false;
	while (ordenado == false && i <= vector.size()-1) {
		ordenado = true;
		for (int j = 0; j < vector.size()-1; j++) {
			if (vector[j] > vector[j + 1]) {
				swap(vector, j, j + 1);
				ordenado = false;
			}
		}
		i += 1;
	}
}

//Ordenamiento por seleccion
template <typename T>
void Sorts<T>::ordenaSeleccion(vector<T> &vector) {

	int min;

	for (int i = 0; i < vector.size()-1; i++) {
		min = i;
		for (int j = i+1; j <= vector.size()-1 ; j++) {
			if (vector[j] < vector[min]) {
				min = j;
			}
		}
		swap(vector, i, min);
	}
}

//Pasa los datos del arreglo B al A
template<typename T>
void Sorts<T>::copyarray(vector<T>&A, vector<T>&B, int low, int high){
  for (int i = low; i <= high; i++){
    A[i] = B[i];
  }
}

template <typename T>
void Sorts<T>::mergeArray(vector<T>&A,vector<T>&B, int low, int mid, int high){
  int i = low;
  int j = mid + 1;
  int k = low;

  while (i <= mid && j <= high){  //Bucle de los arreglos temp y original
    if (A[i] < A[j]){
      B[k] = A[i];  //Asigna el valor en el temporal
      i++;
    }else{
      B[k] = A[j];
      j++;
    }
    k++;
  }
  if (i > mid){
    for (;j <= high; j++){
      B[k++] = A[j];
    }
  }else{
    for (;i <= mid; i++){
      B[k++] = A[i];
    }
  }
}

template <typename T>
void Sorts<T>::mergeSplit(vector<T>&A, vector<T>&B, int low, int high){
  int mid;
  if ((high - low) < 1){ //Caso base
    return;
  }else {
    mid = (low + high) / 2;
    mergeSplit(A,B,low, mid);
    mergeSplit(A,B, mid + 1, high);
    mergeArray(A, B, low, mid, high);
    copyarray(A,B, low, high);
  }

}

template <typename T>
void Sorts<T>::ordenaMerge(vector<T>&vector){
  std::vector<T> temp(vector.size());
  int low = 0;
  int high = vector.size() - 1;
  mergeSplit(vector, temp, low, high);
}

// Busquedas

template <typename T>
int Sorts<T>::busqSecuencial(const vector<T>&vector, int num){

	int posicion;
	bool encontrado = false;
	int i=0;
	while(i<vector.size() && encontrado == false ){

		if (vector[i] == num ){
			encontrado = true;
			posicion = i;
		}
		i = i+1;
	}

 if (encontrado == true){
	 return posicion;
 }
 else{
	 return -1;
 }

}

template<typename T>
int Sorts<T>::busqBinaria(const vector<T>&vector, int num){

	int inf = 0;
	int sup = vector.size()-1;

	int mitad = (inf+sup)/2;

	while(inf < sup){

		if (vector[mitad] ==  num){
			return mitad;
		}
		else if(vector[mitad]<num){
				inf = mitad +1;
				mitad =  (inf+sup)/2;
		}
		else{
				sup = mitad - 1;
				mitad = (inf+sup)/2;
		}
	}
	return inf;
}


#endif
