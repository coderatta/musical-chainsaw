#ifndef MAPA_H
#define MAPA_H

#define EMPTY_SPACE '.'
#define HORIZONTAL_WALL '-'
#define VERTICAL_WALL '|'
#include "pacman.h"
#include <stdio.h>
#include <stdlib.h>
struct Map
{
    char **matriz;
    int linhas;
    int colunas;
};

typedef struct Map m;

void allocate_memory(m *mapa);
FILE *open_file(m *mapa);
void load_map(FILE *arquivo_mapas, m *mapa);
void print_map(m *mapa);
void free_memory(m *mapa);
void locate_character(m *mapa, c *character, char character_symbol);

#endif /* MAPA_H */