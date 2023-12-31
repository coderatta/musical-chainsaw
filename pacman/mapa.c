#include "mapa.h"

void free_memory(m *mapa)
{
    for (int i = 0; i < mapa->linhas; i++)
    {
        free(mapa->matriz[i]);
    }
    free(mapa->matriz);
}

void print_map(m *mapa)
{
    for (int i = 0; i < mapa->linhas; i++)
    {
        printf("%s\n", mapa->matriz[i]);
    }
}

void load_map(FILE *map_file, m *mapa)
{
    for (int i = 0; i < mapa->linhas; i++)
    {
        fscanf(map_file, "%s", mapa->matriz[i]);
    }
}

void allocate_memory(m *mapa)
{
    mapa->matriz = malloc(sizeof(char *) * mapa->linhas); // aloca ponteiros de char(arrays) para as linhas
    for (int i = 0; i < mapa->linhas; i++)
    {
        mapa->matriz[i] = malloc(sizeof(char) * (mapa->colunas + 1)); // aloca memoria para as colunas dentro das linhas
    }
}

FILE *open_file(m *mapa)
{
    FILE *map_file = fopen("mapas.txt", "r");
    if (map_file == 0)
    {
        fprintf(stderr, "Erro a leitura do mapa\n");
        exit(EXIT_FAILURE);
    }
    fscanf(map_file, "%d %d", &(mapa->linhas), &(mapa->colunas));
    return map_file;
}

void locate_character(m *mapa, c *player, char player_symbol)
{
    for (int i = 0; i < mapa->linhas; i++)
    {
        for (int j = 0; j < mapa->colunas; j++)
        {
            if (mapa->matriz[i][j] == player_symbol)
            {
                player->x = j;
                player->y = i;
                break;
            }
        }
    }
}