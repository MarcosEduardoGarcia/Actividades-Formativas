# Analísis de complejidad

**add**

Complejidad: O(log(n))

Para llevar a cabo el add comenzaremos añadiendo el nodo de la misma manera en que lo hariamos en un BST comparando el valor escogiendo entre derecha e izquierda una vez alcanzado la posición se aplicará la función recursiva splay que nos permitirá mandar el elemento al root mediante rotaciones que de cierta forma terminara haciendo un balance al árbol quitando lo degenerado en caso de que este caso se presente

**remove**

Complejidad: O(log(n)

Existen dos casos que se considerarian los peores el primero donde el elemento a borrar se encuentre al final del arbol o que el elemento no existe en la estructura en esos casos el elemento debe eliminarse como se haría un bst y posteriormente realizar un acomodo en el padre del hijo borrado llevandolo asi al root del árbol


**find**

Complejidad: O(n)

Las busquedas en splay trees es identica a como la hariamos en un BST pero una vez encontrado el elemento lo conveetiremos en el root del arbol el peor caso sería tener un arbol degenerado teniendo en cuenta que una vez que este elemento se llegara a buscar el arbol se balancearia volviendo el tiempo O(n) en log(n) por lo que el arbol degenarado desaparece para siempre.

**inorder**

Complejidad: O(n)

Inorder es una fucnión que nos permite imprimir el arbol por lo que si se desea visuzalizar al completo es necesario recorrer cada uno de los nodos del arbol para saber cual es su valor y mandarlo a consola por lo que se tendran que realizar tantos pasos como numero de nodos

**size**

Complejidad. O(1) 

Esta será una función que nos regresa el tamaño del arbol al ser este un atributo de la clase y mandarlo a llamar mediante una funcion que unicamente regresa un valor su tiempo será siempre constante.
