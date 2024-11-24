#include <stdio.h>
#include <stdlib.h>

// Funkcja do obs³ugi b³êdów otwierania pliku
void handle_file_error(FILE* file, const char* filename) {
    if (!file) {
        fprintf(stderr, "B³¹d: Nie mo¿na otworzyæ pliku %s.\n", filename);
        exit(EXIT_FAILURE);
    }
}

// Funkcja do obs³ugi b³êdów alokacji pamiêci
void handle_memory_error(void* ptr, const char* variable_name) {
    if (!ptr) {
        fprintf(stderr, "B³¹d: Nie uda³o siê zaalokowaæ pamiêci dla %s.\n", variable_name);
        exit(EXIT_FAILURE);
    }
}

// Funkcja do obs³ugi niepoprawnego indeksu
void handle_invalid_index(int index, int max_index) {
    if (index < 0 || index >= max_index) {
        fprintf(stderr, "B³¹d: Niepoprawny indeks %d (dozwolone 0-%d).\n", index, max_index - 1);
        exit(EXIT_FAILURE);
    }
}
