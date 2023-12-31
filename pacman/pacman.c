#include "pacman.h"
#include "mapa.h"

m mapa;
c player;
c ghost1;

void captura_movimento()
{
    char command;
    scanf(" %c", &command);
    move_player(command);
}

void move_player(char command)
{
    locate_character(&mapa, &player, PLAYER);

    int new_x_pos = player.x;
    int new_y_pos = player.y;

    switch (command)
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

    verify_collision(new_x_pos, new_y_pos, PLAYER, &player);
}

void verify_collision(int new_x_pos, int new_y_pos, char character, c *position)
{
    if (is_obstacle(new_x_pos, new_y_pos))
    {
        return;
    }
    else if (ghost_touched_player(ghost1, player))
    {
        printf("Voce perdeu!\n");
        exit(EXIT_SUCCESS);
    }
    else
    {
        mapa.matriz[new_y_pos][new_x_pos] = character;
        mapa.matriz[position->y][position->x] = EMPTY_SPACE;
    }
}

int ghost_touched_player(c ghost1, c player)
{
    return ghost1.x == player.x && ghost1.y == player.y;
}

int is_obstacle(int new_x_pos, int new_y_pos)
{
    return mapa.matriz[new_y_pos][new_x_pos] == HORIZONTAL_WALL || mapa.matriz[new_y_pos][new_x_pos] == VERTICAL_WALL;
}

void move_ghost()
{
    locate_character(&mapa, &ghost1, GHOST1);

    char possible_directions[] = {UP, DOWN, LEFT, RIGHT};
    srand(time(NULL));
    int index = rand() % 4;

    int new_x_pos = ghost1.x;
    int new_y_pos = ghost1.y;

    switch (possible_directions[index])
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
    }

    verify_collision(new_x_pos, new_y_pos, GHOST1, &ghost1);
}

int main()
{
    FILE *map_file = open_file(&mapa);

    allocate_memory(&mapa);

    load_map(map_file, &mapa);

    do
    {
        print_map(&mapa);
        move_ghost();
        captura_movimento();
    } while (1);

    free_memory(&mapa);

    fclose(map_file);
    return 0;
}