void libera_memoria();
void desenha_mapa();
void carrega_mapa(FILE *arquivo_mapas);
void aloca_memoria();
FILE *abre_arquivo();
void captura_movimento();
void move_presonagem(char comando);
int acabou();
void localiza_personagem(int *x_axis, int *y_axis);

struct mapa
{
    char **matriz;
    int linhas;
    int colunas;
};
