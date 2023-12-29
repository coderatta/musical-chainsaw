struct Mapa
{
    char **matriz;
    int linhas;
    int colunas;
};

typedef struct Mapa m;

void libera_memoria(m *mapa);
void desenha_mapa(m *mapa);
void carrega_mapa(FILE *arquivo_mapas, m *mapa);
void aloca_memoria(m *mapa);
FILE *abre_arquivo(m *mapa);
