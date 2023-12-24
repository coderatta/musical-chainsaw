#include <stdio.h>
#include <stdlib.h>

int main()
{

    // abre o arquivo e salva as linhas e colunas
    FILE *arquivo_mapas = fopen("mapas.txt", "r");
    if (arquivo_mapas == 0)
    {
        fprintf(stderr, "Erro a leitura do mapa\n");
        exit(EXIT_FAILURE);
    }
    int linhas;
    int colunas;
    fscanf(arquivo_mapas, "%d", &linhas);
    fscanf(arquivo_mapas, "%d", &colunas);
    char mapa[linhas][colunas + 1]; // mais 1 por causa do \0 no final da string

    // salva o mapa na matriz
    for (int i = 0; i < linhas; i++)
    {
        fscanf(arquivo_mapas, "%s", mapa[i]);
    }

    // desenha o mapa
    for (int i = 0; i < linhas; i++)
    {
        printf("%s\n", mapa[i]);
    }

    fclose(arquivo_mapas);
    return 0;
}