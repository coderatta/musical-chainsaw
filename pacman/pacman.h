#define UP 'w'
#define DOWN 's'
#define LEFT 'a'
#define RIGHT 'd'
#define PLAYER '@'
#define GHOST1 'F'

int is_obstacle(int new_x_pos, int new_y_pos);
void move_presonagem(char comando);
void captura_movimento();
void ghost_touched_player();
void move_fantasmas();