#include <stdio.h>
#include <stdlib.h>

// Funkcja do obs�ugi b��d�w otwierania pliku
void handle_file_error(FILE* file, const char* filename) {
    if (!file) {
        fprintf(stderr, "B��d: Nie mo�na otworzy� pliku %s.\n", filename);
        exit(EXIT_FAILURE);
    }
}

// Funkcja do obs�ugi b��d�w alokacji pami�ci
void handle_memory_error(void* ptr, const char* variable_name) {
    if (!ptr) {
        fprintf(stderr, "B��d: Nie uda�o si� zaalokowa� pami�ci dla %s.\n", variable_name);
        exit(EXIT_FAILURE);
    }
}

// Funkcja do obs�ugi niepoprawnego indeksu
void handle_invalid_index(int index, int max_index) {
    if (index < 0 || index >= max_index) {
        fprintf(stderr, "B��d: Niepoprawny indeks %d (dozwolone 0-%d).\n", index, max_index - 1);
        exit(EXIT_FAILURE);
    }
}
