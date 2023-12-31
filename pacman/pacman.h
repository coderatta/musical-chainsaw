#ifndef PACMAN_H
#define PACMAN_H

#define UP 'w'
#define DOWN 's'
#define LEFT 'a'
#define RIGHT 'd'
#define PLAYER '@'
#define GHOST1 'F'
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
struct Character
{
    int x;
    int y;
};

typedef struct Character c;

int is_obstacle(int new_x_pos, int new_y_pos);
void move_player(char comando);
void captura_movimento();
void move_ghost();
void verify_collision(int new_x_pos, int new_y_pos, char character, c *position);
int ghost_touched_player(c ghost1, c player);

#endif /* PACMAN_H */