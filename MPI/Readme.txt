Jhefry Ferney Martinez 2205002 y Yosert Alejandro Higuera 2205003

En el código de Postman, podemos ver que se divide el arreglo en bloques y cada proceso
realiza una búsqueda binaria en su bloque asignado. Después, se reduce el tiempo de ejecución 
local utilizando MPI_Reduce() para obtener el tiempo total de ejecución.

En el código de Binary Search, se divide la lista entre los procesos utilizando MPI_Scatter().
Cada proceso ordena su sublista utilizando el algoritmo de ordenamiento de burbuja y luego se recopilan
las sublistas ordenadas utilizando MPI_Gather(). Finalmente, el proceso raíz imprime la lista 
ordenada y realiza una búsqueda binaria para encontrar una clave especificada por el usuario.

Los dos códigos muestran cómo MPI puede utilizarse para distribuir tareas entre varios procesos y reducir
el tiempo de ejecución de operaciones intensivas en CPU al realizarlas en paralelo. 