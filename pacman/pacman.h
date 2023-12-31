#define UP 'w'
#define DOWN 's'
#define LEFT 'a'
#define RIGHT 'd'
#define PLAYER '@'

int acabou();
int is_obstacle(int new_x_pos, int new_y_pos);
void verifica_colisao(int new_x_pos, int new_y_pos);
void move_presonagem(char comando);
void captura_movimento();