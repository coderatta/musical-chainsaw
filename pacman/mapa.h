#define EMPTY_SPACE '.'
#define HORIZONTAL_WALL '-'
#define VERTICAL_WALL '|'
struct Map
{
    char **matriz;
    int linhas;
    int colunas;
};
struct Character
{
    int x;
    int y;
};

typedef struct Character c;
typedef struct Map m;

void libera_memoria(m *mapa);
void desenha_mapa(m *mapa);
void carrega_mapa(FILE *arquivo_mapas, m *mapa);
void aloca_memoria(m *mapa);
FILE *abre_arquivo(m *mapa);
void localiza_personagem(m *mapa, c *character, char character_symbol);
void verifica_colisao(int new_x_pos, int new_y_pos, char character, c *position);