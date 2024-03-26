#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <omp.h>

#define SIZE 3000  

void binary_search(int[], int, int, int);
void bubble_sort(int[], int);

int main()
{
    int key, i;
    int list[SIZE];

    srand(time(NULL));
    printf("Generated list:\n");
    for(i = 0; i < SIZE; i++)
    {
        list[i] = rand() % 3000; // Cambiado a números aleatorios entre 0 y 3000
        printf("%d ", list[i]);
    }

    double start_time = omp_get_wtime();

    bubble_sort(list, SIZE);
    printf("\n\nSorted list:\n");
    for(i = 0; i < SIZE; i++)
    {
        printf("%d ", list[i]);
    }
    
    key = list[rand() % SIZE];
    printf("\n\nAutomatically chosen key: %d\n", key);
    binary_search(list, 0, SIZE - 1, key);

    double end_time = omp_get_wtime();
    printf("\nTime taken: %f seconds\n", end_time - start_time);

    return 0;
}

void bubble_sort(int list[], int size)
{
    int temp, i, j;
    for (i = 0; i < size; i++)
    {
        for (j = 0; j < size - 1; j++)
        {
            if (list[j] > list[j + 1])
            {
                temp = list[j];
                list[j] = list[j + 1];
                list[j + 1] = temp;
            }
        }
    }
}

void binary_search(int list[], int lo, int hi, int key)
{
    int mid;

    if (lo > hi)
    {
        printf("Key not found\n");
        return;
    }
    mid = (lo + hi) / 2;
    if (list[mid] == key)
    {
        printf("Key found at index %d\n", mid);
    }
    else if (list[mid] > key)
    {
        binary_search(list, lo, mid - 1, key);
    }
    else if (list[mid] < key)
    {
        binary_search(list, mid + 1, hi, key);
    }
}



