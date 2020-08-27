# Análisis de complejidad asintótica 

**Suma iterativa**

Esta función presenta una complejidad temporal lineal O(n):
n siendo el numero hasta el que se quiera sumar se entrará a un ciclo for que ira de uno hasta n dandonos el O(n) dentro del ciclo se ejecutan instruccciones simples O(1) multiplicando O(n) * O(1) sera igual a O(n)

Ejemplo

Si se quiere calcular la suma iterativa para 3: Entramos al ciclo en 1 y en una variable vamos sumando el iterador (1), entramos de nuevo al ciclo en 2 y en nuestra variable sumamos el valor del iterador (2) por ultimo entramos en 3 sumamos el iterador con valor 3 y salimos del ciclo for por lo que observamos que el tiempo es lineal O(n) tantos pasos como numero de datos.


**Suma Recursiva**

Esta función presenta una complejidad temporal lineal O(n):
n representa el numero hasta el que se quiere saber la suma desde 1 hasta n, mediante recursividad si n es igual a 0 regresaremos un uno sino a n le iremos sumando la funcion recursiva de n-1 como podemos ver el decremento es constante por lo que sera lineal O(n)

Ejemplo 

Cuando n es igual a 3, dentro de nuestra función tenemos un caso base donde si n=0 regresamos un 0 mientras eso no se cumpla aplicaremos n + sumaIterativa(n-1)


      sumaIterativa(3)¬

            3 + sumaIterativa(2)¬
      
                  2 + sumaIterativa(1)¬
              
                        1 + sumaIterativa(0)¬
                   
                        0
                      
 Obteniendo que el numero de pasos es igual a n por lo tanto es lineal O(n)
 
 
 **Suma directa**
 
 Para hallar la suma de todos los numeros consecutivos hasta un número n existe un método desarrollado por Gauss la suma gaussiana
 donde se tiene (n*(n+1))/2 lo que daría un tiempo constante pues no importa el tamaño de n se realiza en tiempo constante.
                      

