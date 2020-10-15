# Analisis de complejidad funciones

**visit()**

 Complejidad: O(n)
 
 Esta funcion se encarga de imprimir el arbol en preorder, inorder, postorder y level by level para cada una de estas funciones se tiene que recorrer todo el arbol pues se requiere imprimir cada uno de los valores almacenados en los nodos de tal manera que se realizaran n operaciones como numero de nodos se tengan en el arreglo todo esto mediante recursividad
 
 **height**
 
 Complejidad: O(n)
 
 Esta podria considerarse una funcion O(log n) sin embargo se considera el peor de los casos y este será cuando se tenga un arbol degenerado yendo todo en una misma rama ocasionando que se tenga que recorrer todo el arbol siendo este el peor tiempo posible.
 
 **ancestors**
 
 Complejidad: O(n)
 
 AL ser un arbol igual que en el caso anterior en muchos casos puede ser O(log n) sin embargo al tener un arbol degenerado donde todo se va a una misma rama se tendra que recorrer todo el arbol para luego imprimir los ancestros lo que requerira n instruciones como cantidad de nodos en el arbol.
 
 **whatlevelamI**
 
 Complejidad: O(n)
 
 En los mejores de los casos se presentaría una complejidad de O(log n) pues se irian descartando la mitad de los valores cada vez sin embargo para el peor de los casos donde se tenga un arbol degenerado y se quiera saber el nivel del ultimo hijo se tendra que recorrer todo el arbol para encontrar dicho valor siendo asi O(n)

