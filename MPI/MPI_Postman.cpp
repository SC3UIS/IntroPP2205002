// Códigos estudiantes: 2205003_2205002
#include <iostream>
#include <mpi.h>
#include <cstdlib>

using namespace std;

void binarySearch(int *arr, int start, int end, int key, int rank)
{
    while (start <= end)
    {
        int mid = (start + end) / 2;
        if (arr[mid] == key)
        {
            cout << "Element found by processor " << rank << ".\n";
            return;
        }
        else if (arr[mid] < key)
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }
    cout << "Element not found by processor " << rank << ".\n";
}

int main(int argc, char **argv)
{
    MPI_Init(&argc, &argv);

    int rank, size;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    int n = 4000;
    int *arr = new int[n];

    for (int i = 0; i < n; i++)
    {
        arr[i] = i + 1;
    }

    int key = 100; // Element to search
    int blocks = 3;
    int blockSize = n / blocks;
    int startIdx = rank * blockSize;
    int endIdx = (rank + 1) * blockSize - 1;

    double start = MPI_Wtime();
    binarySearch(arr, startIdx, endIdx, key, rank);
    double end = MPI_Wtime();

    double local_execution_time = (end - start) * 1000;

    double total_execution_time;

    MPI_Reduce(&local_execution_time, &total_execution_time, 1, MPI_DOUBLE, MPI_SUM, 0, MPI_COMM_WORLD);

    if (rank == 0)
    {
        cout << "Total execution time: " << total_execution_time << " milliseconds." << endl;
    }

    delete[] arr;

    MPI_Finalize();

    return 0;
}
