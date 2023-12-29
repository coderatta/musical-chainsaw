#include <stdio.h>
#include <stdlib.h>
#include "pacman.h"

struct mapa mapa1;

void libera_memoria()
{
    for (int i = 0; i < mapa1.linhas; i++)
    {
        free(mapa1.matriz[i]);
    }
    free(mapa1.matriz);
}

void desenha_mapa()
{
    for (int i = 0; i < mapa1.linhas; i++)
    {
        printf("%s\n", mapa1.matriz[i]);
    }
}

void carrega_mapa(FILE *arquivo_mapas)
{
    for (int i = 0; i < mapa1.linhas; i++)
    {
        fscanf(arquivo_mapas, "%s", mapa1.matriz[i]);
    }
}

void aloca_memoria()
{
    mapa1.matriz = malloc(sizeof(char *) * mapa1.linhas); // aloca ponteiros de char(arrays) para as linhas
    for (int i = 0; i < mapa1.linhas; i++)
    {
        mapa1.matriz[i] = malloc(sizeof(char) * (mapa1.colunas + 1)); // aloca memoria para as colunas dentro das linhas
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
    fscanf(arquivo_mapas, "%d %d", &mapa1.linhas, &mapa1.colunas);
    return arquivo_mapas;
}

void captura_movimento()
{
    char comando;
    scanf(" %c", &comando);
    move_presonagem(comando);
}

void localiza_personagem(int *x_axis, int *y_axis)
{
    for (int i = 0; i < mapa1.linhas; i++)
    {
        for (int j = 0; j < mapa1.colunas; j++)
        {
            if (mapa1.matriz[i][j] == '@')
            {
                *x_axis = j;
                *y_axis = i;
                break;
            }
        }
    }
}

void move_presonagem(char comando)
{
    int x_axis;
    int y_axis;

    localiza_personagem(&x_axis, &y_axis);

    mapa1.matriz[y_axis][x_axis] = '.';

    switch (comando)
    {
    case 'w':
        y_axis -= 1;
        break;
    case 's':
        y_axis += 1;
        break;
    case 'a':
        x_axis -= 1;
        break;
    case 'd':
        x_axis += 1;
        break;
    default:
        break;
    }
    // verifica se bateu em uma parede
    if (mapa1.matriz[y_axis][x_axis] == '-' || mapa1.matriz[y_axis][x_axis] == '|')
    {
        printf("You lost");
        exit(EXIT_SUCCESS);
    }
    else
    {
        mapa1.matriz[y_axis][x_axis] = '@';
    }
}

int acabou()
{
    return 0;
}

int main()
{
    FILE *arquivo_mapas = abre_arquivo();

    aloca_memoria();

    carrega_mapa(arquivo_mapas);

    do
    {
        desenha_mapa();

        captura_movimento();
    } while (!acabou());

    libera_memoria();

    fclose(arquivo_mapas);
    return 0;
}