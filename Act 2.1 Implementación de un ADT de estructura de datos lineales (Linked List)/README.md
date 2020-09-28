# ANÁLISIS DE COMPLEJIDAD DE FUNCIONES

**Función add**

Esta función presenta una complejidad O(n) estamos considerando el peor de los casos donde se desee añadir un nodo al final donde se entra en un loop que se ejecuta mientras la Flecha del nodo apunte a otro nodo y en el momento que llegue a null colocará ahi el elemento por lo que tiene que hacer n iteraciones igual a la cantidad de elementos en la lista

**Función find**

Esta posicion regresa la posición donde se encuntra un elemento solicitado por lo que se tiene que recorrer la lista desde el comienzo hasta que el valor pedido sea igual al valor guardado en el nodo y en caso de no encontrarlo despues de recorrer toda la estrutura se regresará un -1 por lo cual esta función será 0(n)

**Función update**

Esta funcion recibe como parametro la posicion y el nuevo valor que se actualizará en el nodo se tiene que recorrer con un ciclo while para llegar hasta el nodo pedido y realizar el cambio por lo que tomara n numeros de pasos como elementos siendo O(n)

**Función remove**

Esta fucnción posee un condicional en caso de que se quiera eliminar el primer elemento esto se hara en tiempo constante O(1) pero como se toma el peor caso se entrará en un ciclo while recorriendo la lista en busca del indice que se quiera borrar mediante dos apuntadores con los cuales se lograra enlazar la lista con el elemento proximo del que será borrado para no perder los elementos que hay despues esto requiere ir hasta el indice con la misma cantidad de pasos que elementos siendo O(n)
