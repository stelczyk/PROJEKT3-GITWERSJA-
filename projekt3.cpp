
#include<stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)

// Deklaracje zmiennych globalnych z functions.cpp
extern int n;           // Rozmiar wektora
extern int m;           // Liczba wektorów
extern double* vectors; // Tablica przechowująca wszystkie wektory
extern double* result;  // Wektor wynikowy

// Deklaracje funkcji z functions.cpp
void allocate_memory();
void free_memory();
void read_dimensions(FILE* file);
void read_vectors(FILE* file);
void write_vector(FILE* file, const double* vector, int size);
void select_and_sum_vectors();

// Deklaracje funkcji z errors.cpp
void handle_file_error(FILE* file, const char* filename);

int main() {
    FILE* input = fopen("input.txt", "r");
    FILE* output = fopen("output.txt", "w");

    // Sprawdzanie poprawności otwarcia plików
    handle_file_error(input, "input.txt");
    handle_file_error(output, "output.txt");

    // Odczyt danych z pliku
    read_dimensions(input);
    allocate_memory();
    read_vectors(input);

    // Wybór wektorów i sumowanie
    select_and_sum_vectors();

    // Zapis wyniku do pliku i na ekran
    printf("Wynikowy wektor: ");
    write_vector(stdout, result, n);
    fprintf(output, "Wynikowy wektor: ");
    write_vector(output, result, n);

    // Sprzątanie i zamknięcie plików
    free_memory();
    fclose(input);
    fclose(output);

    return 0;
}
