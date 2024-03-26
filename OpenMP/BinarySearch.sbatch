#!/bin/bash
#SBATCH -p normal
#SBATCH --ntasks=10
#SBATCH --output=out_BinarySearch.txt
#SBATCH --error=error_%j.txt
#SBATCH --mail-user=lllzook2030@gmail.com
#SBATCH --cpus-per-task=10
#SBATCH -w ExaDELL

gcc -fopenmp omp_BinarySearch.c -o omp_BinarySearch
./omp_BinarySearch
