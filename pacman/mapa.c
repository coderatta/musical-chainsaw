#include <stdio.h>
#include <stdlib.h>
#include "mapa.h"

void libera_memoria(m *mapa)
{
    for (int i = 0; i < mapa->linhas; i++)
    {
        free(mapa->matriz[i]);
    }
    free(mapa->matriz);
}

void desenha_mapa(m *mapa)
{
    for (int i = 0; i < mapa->linhas; i++)
    {
        printf("%s\n", mapa->matriz[i]);
    }
}

void carrega_mapa(FILE *arquivo_mapas, m *mapa)
{
    for (int i = 0; i < mapa->linhas; i++)
    {
        fscanf(arquivo_mapas, "%s", mapa->matriz[i]);
    }
}

void aloca_memoria(m *mapa)
{
    mapa->matriz = malloc(sizeof(char *) * mapa->linhas); // aloca ponteiros de char(arrays) para as linhas
    for (int i = 0; i < mapa->linhas; i++)
    {
        mapa->matriz[i] = malloc(sizeof(char) * (mapa->colunas + 1)); // aloca memoria para as colunas dentro das linhas
    }
}

FILE *abre_arquivo(m *mapa)
{
    FILE *arquivo_mapas = fopen("mapas.txt", "r");
    if (arquivo_mapas == 0)
    {
        fprintf(stderr, "Erro a leitura do mapa\n");
        exit(EXIT_FAILURE);
    }
    fscanf(arquivo_mapas, "%d %d", &(mapa->linhas), &(mapa->colunas));
    return arquivo_mapas;
}

void localiza_personagem(m *mapa, c *player, char player_symbol)
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