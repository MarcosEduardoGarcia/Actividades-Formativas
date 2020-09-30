# Análisis de complejidad Listas doblemente encadenadas

**FUNCIONES**

**ADD**

Complejidad: O(1) 

Esta función permite añadir un nuevo elemento a la lista donde se presenta un condicional donde se comprueba si la lista esta vacia de ser ese el caso se añadira ese elemento como primero a la lista de lo contrario se ira por la rama de else que colocara el nuevo elemento al final esto se ejecuta en tiempo constante ya que tomamos tail desde el inicio no hay que recorrer la lista para llegar al final al no presentarse ciclos por lo tanto será O(1)

**FIND**

Complejidad: O(n)

Esta fucnión nos permite encontrar el indice donde se encuentra un elemento esto se hara mediante un ciclo while que evaluara el valor que se busca avanzando en la lista y si lo encuentra dará la posicion de lo contrario excedera la condicion del while por lo que regresará un -1.

**UPDATE**

Complejidad: O(n)

Esta función recibe el indice y el valor por el que se quiere reemplezar el valor iremos recorriendo la lista hasta encontrar el indice y cambiaremos el valor por el nuevo se tendran que hacer n pasos por numero de elementos en la lista obteniendo una complejidad de O(n)

**REMOVE**

Complejidad: O(n)

Esta funcion tiene como parametro el indice del elemento que se borrará si el indice es cero se hará en tiempo O(1) pero considerando el peor caso entraremos en un ciclo while llegando al indice donde se quiera borrar el elemento ejecutando instrucciones se tuvo que hacer n instrucciones como numero de elementos en la lista obteniendo asi el O(n)


