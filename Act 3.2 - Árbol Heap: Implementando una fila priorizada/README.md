# Análisis de complejidad


**push(T valor)**

Complejidad: O(log(n))

Mediante esta función es posible agregar elementos al heap se agregaran de manera consecutiva en el arreglo de heap y en el peor de los casos el elementos violara las reglas del heap donde los hijos tiene que ser mayores al padre por lo que se ejecutara la funcion recursiva heapify_push de ese elemento la cual realiza intercambio entre el hijo y el padre unicamente recocriendo los nodos de padre en padre hasta llegar a una posicion donde sea mayor que el padre al solo recorrerse una rama el tiempo es log(n)

**pop()**
 Complejidad: O(log(n))
 
 Esta funcion es la que se encarga de sacar al valor mas pequeño dentro del heap y colocar el ultimo nodo añadido para posteriormente ejecutar un heapify_pop que movera ese nodo comparando y buscando el hijo menor para realizar el cambio descartando en cada vuelta recursiva la mitad del heap siendo asi O(log(n)
 
 **top**
 
 Complejidad: O(1)
 
 Esta función devolvera unicamente el valor que se encuentra en la posicion cero del areglo pues es el elemento superior que sera el siguiente en salir.
 
 **empty**
 
 Complejidad: O(1)
 
 Esta funcion devolvera un valor booleano en caso de que el heap se encuentre vacio siendo solo una sentencia simple es constante
 
 **size**
 
 Complejidad: O(1)
 
 Esta funcion devolvera el atributo de tamaño del heap este tamaño se actualiza cada vez que añadimos un valor al heap es una instruccion simple por lo tanto es en tiempo constante 
