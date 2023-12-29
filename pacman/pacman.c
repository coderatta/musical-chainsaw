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
    localiza_personagem(&mapa, &player, '@');

    mapa.matriz[player.y][player.x] = '.';

    switch (comando)
    {
    case 'w':
        player.y -= 1;
        break;
    case 's':
        player.y += 1;
        break;
    case 'a':
        player.x -= 1;
        break;
    case 'd':
        player.x += 1;
        break;
    default:
        break;
    }
    // verifica se bateu em uma parede
    if (mapa.matriz[player.y][player.x] == '-' || mapa.matriz[player.y][player.x] == '|')
    {
        printf("You lost\n");
        exit(EXIT_SUCCESS);
    }
    else
    {
        mapa.matriz[player.y][player.x] = '@';
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