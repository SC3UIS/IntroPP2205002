# Binary Search en Lista Ordenada (con Bubble Sort Paralelo)

Este programa en C genera una lista de números aleatorios, la ordena usando el algoritmo de bubble sort paralelo y luego realiza una búsqueda binaria en la lista ordenada para encontrar una clave aleatoria.

## Funcionamiento

1. **Generación de elementos aleatorios**: El programa genera una lista de números aleatorios entre 0 y 5000.

2. **Ordenación de la lista**: Utiliza el algoritmo de bubble sort paralelo para ordenar la lista de números generados.

3. **Búsqueda binaria**: Realiza una búsqueda binaria en la lista ordenada para encontrar una clave aleatoria. Si la clave se encuentra, imprime el índice donde se encuentra. Si no se encuentra, imprime un mensaje indicando que la clave no se encontró.

## Compilación y Ejecución

Para compilar el programa, ejecuta el siguiente comando en la terminal:

gcc -o binary_search binary_search.c -fopenmp


Luego, para ejecutar el programa, simplemente ejecuta el archivo generado:


## Requisitos

- Compilador de C compatible con OpenMP.
- Biblioteca OpenMP.

## Notas

- El tamaño de la lista está definido como `SIZE` en el código. Por defecto, está configurado en 3000.

- El rango de los números aleatorios generados es de 0 a 5000.

- La búsqueda binaria se realiza en la lista ordenada generada.

- El programa muestra la clave seleccionada aleatoriamente y el resultado de la búsqueda.

