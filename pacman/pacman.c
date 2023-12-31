#include <stdio.h>
#include <stdlib.h>
#include "pacman.h"
#include "mapa.h"

m mapa;
p player;

void captura_movimento()
{
    char comando;
    scanf(" %c", &comando);
    move_presonagem(comando);
}

void move_presonagem(char comando)
{
    localiza_personagem(&mapa, &player, PLAYER);

    int new_x_pos = player.x;
    int new_y_pos = player.y;

    switch (comando)
    {
    case UP:
        new_y_pos--;
        break;
    case DOWN:
        new_y_pos++;
        break;
    case LEFT:
        new_x_pos--;
        break;
    case RIGHT:
        new_x_pos++;
        break;
    default:
        break;
    }

    verifica_colisao(new_x_pos, new_y_pos);
}

void verifica_colisao(int new_x_pos, int new_y_pos)
{
    if (is_obstacle(new_x_pos, new_y_pos))
    {
        return;
    }
    else
    {
        mapa.matriz[new_y_pos][new_x_pos] = PLAYER;
        mapa.matriz[player.y][player.x] = EMPTY_SPACE;
    }
}

int is_obstacle(int new_x_pos, int new_y_pos)
{
    return mapa.matriz[new_y_pos][new_x_pos] == HORIZONTAL_WALL || mapa.matriz[new_y_pos][new_x_pos] == VERTICAL_WALL;
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