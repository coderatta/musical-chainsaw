#include <stdio.h>
#include <stdlib.h>
#include "pacman.h"

char **mapa;
int linhas;
int colunas;

void libera_memoria()
{
    for (int i = 0; i < linhas; i++)
    {
        free(mapa[i]);
    }
    free(mapa);
}

void desenha_mapa()
{
    for (int i = 0; i < linhas; i++)
    {
        printf("%s\n", mapa[i]);
    }
}

void carrega_mapa(FILE *arquivo_mapas)
{
    for (int i = 0; i < linhas; i++)
    {
        fscanf(arquivo_mapas, "%s", mapa[i]);
    }
}

void aloca_memoria()
{
    mapa = malloc(sizeof(char *) * linhas); // aloca ponteiros de char(arrays) para as linhas
    for (int i = 0; i < linhas; i++)
    {
        mapa[i] = malloc(sizeof(char) * (colunas + 1)); // aloca memoria para as colunas dentro das linhas
    }
}

FILE *abre_arquivo()
{
    FILE *arquivo_mapas = fopen("mapas.txt", "r");
    if (arquivo_mapas == 0)
    {
        fprintf(stderr, "Erro a leitura do mapa\n");
        exit(EXIT_FAILURE);
    }
    fscanf(arquivo_mapas, "%d %d", &linhas, &colunas);
    return arquivo_mapas;
}

int main()
{

    FILE *arquivo_mapas = abre_arquivo();

    aloca_memoria();

    carrega_mapa(arquivo_mapas);

    desenha_mapa();

    libera_memoria();

    fclose(arquivo_mapas);
    return 0;
}