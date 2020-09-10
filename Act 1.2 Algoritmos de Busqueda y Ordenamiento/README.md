# Analisis de complejidad

**Ordena Selección

El ordenamiento por seleccion es de complejidad O(n^2):

El algoritmo busca el elemento mas pequeño en el arreglo y lo colocara en la primera posicion luego lo recorrera buscando el segundo mas pequeño y colocarlo en la segunda posición
esto se hace con dos for anidados entramos en el  primer for y obtenemos n al entrar al siguiente for es otra n y dentro se ejecuta un condicional O(1) hasta terminar el for sale de el y realiza un swamp para poner el numero mas pequeño en la primera posicion completando el primer ciclo del for superior por lo que la complejidad sera n*n*O(1)= O(n^2)

**Ordena burbuja

El ordenamiento por burbuja es de complejidad O(n^2)

El algortimo ira comparando datos contiguos e intercambiandolos si el de la izquierda es mayor que el de la derecha es un while con un for anidado el while se rige por una condicion booleana y el tamaño del vector - 1 esto para hacerlo un poco mas eficiente aun asi tomamos el peor caso dandonos esto una n, dentro el for ira comparando los valores de dos en dos con un condicional dando n, este algoritmo permite ahorrar una vuelta al final pues sino entra en el condicional el valor bool nunca cambia de verdadero saliendo del ciclo pues ya todos los datos se encuentran ordenados la complejidad sera n*n*O(1) = O(n^2)

**Ordena merge




**Busqueda secuencial

La busqueda secuencial será de complejidad O(n) 

El algoritmo sera un ciclo while que seguira mientras no se recorra todo el arreglo o se encunetre el valor al ser un ciclo dara n pasos como numero de datos dentro del while solo hay operaciones simples teniendo O(1) enntonces n*O(1)= O(n)

**Busqueda binaria

La busqueda binaria sera de complejidad O(log(n)) 

El algoritmo crea un arbol binario siempre descartando la mitad de la rama y la mitad de la siguiente y la mitad de la siguiente y asi sucesivamente reduciendo los pasos esto es gracias a los condicionales que van descartando las ramas y podemos ver que para encontrar una posicion se requiere de muy pocos pasos siendo del orden de log n por lo tanto la complejidad sera de O(log(n)) 



