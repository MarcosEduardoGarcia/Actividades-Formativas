# Análisis de complejidad 


**loadGraphList**

Complejidad: O(n)

Esta función es la que se encarga de leer un archivo de texto donde como parametros se incluye el archivo y el numero de vertices y arcos se debe leer cada línea del archivo, encontrar los valores numericos para pasarlos a un una función que añadira dichos valores a una lista de adyacencia por lo que se haran n numero de instrucciones como cantidad de lineas en el archivo de texto siendo asi O(n)


**loadGraphMat**

Complejidad: O(n)

Esta función es la que se encarga de leer un archivo de texto donde como parametros se incluye el archivo y el numero de vertices y arcos se debe leer cada línea del archivo, encontrar los valores numericos para pasarlos a un una función que añadira dichos valores a una matriz de adyacencia por lo que se haran n numero de instrucciones como cantidad de lineas en el archivo de texto siendo asi O(n)

**DFS**

Complejidad: O(Vertice * Arco)

Deepth First Search es una funcion la cual recibe un nodo de partida y un nodo de llegada se recorreran los nodos de manera que se seguira una línea hasta no poder avanzar mas esto se ira haciendo de manera recursiva al no encontrar otro camino se regresará al anterior y se exploraran las ramas que queden por visitar, su complejidad esta determinada por la multiplicacion del número de vertices por el número de arcos, en esta implementacion tomamos el peor caso donde el nodo inicial sería cero y la meta sea el nodo mas alejado de este y haya que pasar por todos los nodos.

**BFS**

Complejidad: O(Vertice * Arco)

Busqueda por amplitud esta se realiza avanzando en cada uno de los vecinos de un nodo y una vez completados se avanza al siguiente y se visitan los vecinos contiguos hasta terminar el grafo en nuestra implementacion se da un nodo de inicio y un nodo meta pero tomaremos el peor de los casos donde se recorrá todo el grafo por lo que la complejidad sera dada por la multiplicación de los vertices por el número de arcos.

