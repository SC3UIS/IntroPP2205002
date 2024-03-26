#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <omp.h>

#define SIZE 3000 // Se cambia el tamaño a 3000

void binary_search(int[], int, int, int);
void bubble_sort(int[], int);

int main() {
    int key;
    int list[SIZE];

    // Generar elementos aleatorios
    printf("Generating random elements...\n");
    srand(time(NULL)); // Semilla de generación de números aleatorios
    #pragma omp parallel for
    for (int i = 0; i < SIZE; i++) {
        list[i] = rand() % 5000; // Genera números aleatorios entre 0 y 5000
    }

    double start_time = omp_get_wtime(); // Guardar el tiempo de inicio

    // Parallelizing bubble sort
    bubble_sort(list, SIZE);

    // Imprimir la lista ordenada
    printf("Sorted list:\n");
    for (int i = 0; i < SIZE; i++) {
        printf("%d ", list[i]);
    }
    printf("\n");

    // Seleccionar una clave aleatoria dentro del rango de la lista
    key = list[rand() % SIZE];

    printf("\n");
    printf("Randomly selected key: %d\n", key);
    binary_search(list, 0, SIZE - 1, key); // Ajuste del límite superior del rango

    double end_time = omp_get_wtime(); // Guardar el tiempo de finalización
    printf("Total execution time: %f seconds\n", end_time - start_time); // Imprimir el tiempo de ejecución

    return 0;
}

void bubble_sort(int list[], int size) {
    int temp;
    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) { // Ajuste del bucle interno para evitar intercambios innecesarios
            if (list[i] > list[j]) {
                temp = list[i];
                list[i] = list[j];
                list[j] = temp;
            }
        }
    }
}

void binary_search(int list[], int lo, int hi, int key) {
    int mid;

    if (lo <= hi) { // Corregido el operador de comparación para incluir el caso en que lo == hi
        mid = lo + (hi - lo) / 2; // Corregido para evitar desbordamientos
        if (list[mid] == key) {
            printf("Key found at index %d\n", mid);
        } else if (list[mid] > key) {
            binary_search(list, lo, mid - 1, key);
        } else {
            binary_search(list, mid + 1, hi, key);
        }
    } else {
        printf("Key not found\n");
    }
}


