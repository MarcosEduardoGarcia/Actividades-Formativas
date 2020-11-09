/*
Act 1.1 Sumas iterativas, recursivas y directas
Marcos Eduardo García Ortiz
A01276213
*/

#ifndef FUNCIONES_H_
#define  FUNCIONES_H_

#include <iostream>

class Funciones{
public:

  int sumaIterativa(int n){
    int suma_total=0;
    for (int i = 1; i <= n; i++) {
      suma_total = suma_total + i;
    }
    return suma_total;
  }

  int sumaRecursiva(int n){
    if (n == 0) {
      return 0;
    }
    else{
      return n + sumaRecursiva(n-1);
    }
}

  int sumaDirecta(int n){

    int result = 0;

    result = (n*(n+1))/2;

    return result;

  }

};



#endif
