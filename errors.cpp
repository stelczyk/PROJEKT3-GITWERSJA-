#include <stdio.h>
#include <stdlib.h>

// Funkcja do obslugi bledów otwierania pliku
void handle_file_error(FILE* file, const char* filename) {
    if (!file) {
        fprintf(stderr, "Blad: Nie mozna otworzyc pliku %s.\n", filename);
        exit(EXIT_FAILURE);
    }
}

// Funkcja do obslugi bledów alokacji pamiêci
void handle_memory_error(void* ptr, const char* variable_name) {
    if (!ptr) {
        fprintf(stderr, "Blad: Nie udalo sie zaalokowac pamieci dla %s.\n", variable_name);
        exit(EXIT_FAILURE);
    }
}

// Funkcja do obslugi niepoprawnego indeksu
void handle_invalid_index(int index, int max_index) {
    if (index < 0 || index >= max_index) {
        fprintf(stderr, "Blad: Niepoprawny indeks  (dozwolone 0-%d).\n", max_index - 1);
        exit(EXIT_FAILURE);
    }
}
