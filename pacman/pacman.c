#include <stdio.h>
#include <stdlib.h>
#include "pacman.h"
#include "mapa.h"

m mapa;

void captura_movimento()
{
    char comando;
    scanf(" %c", &comando);
    move_presonagem(comando);
}

void localiza_personagem(int *x_axis, int *y_axis)
{
    for (int i = 0; i < mapa.linhas; i++)
    {
        for (int j = 0; j < mapa.colunas; j++)
        {
            if (mapa.matriz[i][j] == '@')
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

    mapa.matriz[y_axis][x_axis] = '.';

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
    if (mapa.matriz[y_axis][x_axis] == '-' || mapa.matriz[y_axis][x_axis] == '|')
    {
        printf("You lost\n");
        exit(EXIT_SUCCESS);
    }
    else
    {
        mapa.matriz[y_axis][x_axis] = '@';
    }
}

int acabou()
{
    return 0;
}

int main()
{
    FILE *arquivo_mapas = abre_arquivo(&mapa);

    aloca_memoria(&mapa);

    carrega_mapa(arquivo_mapas, &mapa);

    do
    {
        desenha_mapa(&mapa);

        captura_movimento();
    } while (!acabou());

    libera_memoria(&mapa);

    fclose(arquivo_mapas);
    return 0;
}