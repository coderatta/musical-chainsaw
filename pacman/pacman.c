#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "pacman.h"
#include "mapa.h"

m mapa;
c player;
c ghost1;

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

    verifica_colisao(new_x_pos, new_y_pos, PLAYER, &player);
}

void verifica_colisao(int new_x_pos, int new_y_pos, char character, c *position)
{
    if (is_obstacle(new_x_pos, new_y_pos))
    {
        return;
    }
    else if (!is_obstacle(new_x_pos, new_y_pos))
    {
        mapa.matriz[new_y_pos][new_x_pos] = character;
        mapa.matriz[position->y][position->x] = EMPTY_SPACE;
    }
    else
    {
        ghost_touched_player();
    }
}

void ghost_touched_player()
{
    printf("Voce perdeu!");
    exit(EXIT_SUCCESS);
}

int is_obstacle(int new_x_pos, int new_y_pos)
{
    return mapa.matriz[new_y_pos][new_x_pos] == HORIZONTAL_WALL || mapa.matriz[new_y_pos][new_x_pos] == VERTICAL_WALL;
}

void move_fantasmas()
{
    localiza_personagem(&mapa, &ghost1, GHOST1);

    srand(time(NULL));
    int direcao = rand() % 4;

    int new_x_pos = ghost1.x;
    int new_y_pos = ghost1.y;

    switch (direcao)
    {
    case 0:
        new_y_pos--;
        break;
    case 1:
        new_y_pos++;
        break;
    case 2:
        new_x_pos--;
        break;
    case 3:
        new_x_pos++;
        break;
    }

    verifica_colisao(new_x_pos, new_y_pos, GHOST1, &ghost1);
}

int main()
{
    FILE *arquivo_mapas = abre_arquivo(&mapa);

    aloca_memoria(&mapa);

    carrega_mapa(arquivo_mapas, &mapa);

    do
    {
        desenha_mapa(&mapa);
        move_fantasmas();
        captura_movimento();
    } while (1);

    libera_memoria(&mapa);

    fclose(arquivo_mapas);
    return 0;
}