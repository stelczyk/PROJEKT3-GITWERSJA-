#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)

// Definicje zmiennych globalnych
int n = 0;           // Rozmiar wektora
int m = 0;           // Liczba wektorów
double* vectors = NULL;  // Tablica przechowujaca wszystkie wektory
double* result = NULL;   // Wektor wynikowy

// Deklaracje funkcji z errors.cpp
void handle_file_error(FILE* file, const char* filename);
void handle_memory_error(void* ptr, const char* variable_name);
void handle_invalid_index(int index, int max_index);

// Funkcja alokujaca pamiec
void allocate_memory() {
    vectors = (double*)malloc(n * m * sizeof(double));
    handle_memory_error(vectors, "vectors");

    result = (double*)malloc(n * sizeof(double));
    handle_memory_error(result, "result");
}

// Funkcja zwalniajaca pamiec
void free_memory() {
    free(vectors);
    free(result);
}

// Funkcja odczytujaca wymiary z pliku
void read_dimensions(FILE* file) {
    if (fscanf(file, "%d %d", &n, &m) != 2) {
        fprintf(stderr, "Blad: Nie mozna odczytac wymiarów n i m.\n");
        exit(EXIT_FAILURE);
    }
}

// Funkcja odczytujaca wektory z pliku
void read_vectors(FILE* file) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (fscanf(file, "%lf", &vectors[i * n + j]) != 1) {
                fprintf(stderr, "Blad: Nie mozna odczytac elementu wektora.\n");
                exit(EXIT_FAILURE);
            }
        }
    }
}

// Funkcja zapisujaca wektor do pliku lub na ekran
void write_vector(FILE* file, const double* vector, int size) {
    for (int i = 0; i < size; i++) {
        fprintf(file, "%.2lf ", vector[i]);
    }
    fprintf(file, "\n");
}

// Funkcja pozwalajaca wybrac dwa wektory i obliczajaca ich sume
void select_and_sum_vectors() {
    int index1, index2;
    printf("Dostepne wektory: 0 - %d\n", m - 1);
    printf("Wybierz indeks pierwszego wektora: ");
    scanf("%d", &index1);
    handle_invalid_index(index1, m);

    printf("Wybierz indeks drugiego wektora: ");
    scanf("%d", &index2);
    handle_invalid_index(index2, m);

    // Sumowanie wektorów
    for (int i = 0; i < n; i++) {
        result[i] = vectors[index1 * n + i] + vectors[index2 * n + i];
    }
}
