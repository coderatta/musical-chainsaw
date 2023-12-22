#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <time.h>
#include "forca.h"

#define MAX_WORD_LENGTH 20

char palavrasecreta[MAX_WORD_LENGTH];
char chutes[26];
int total_de_chutes = 0;

void captura_chute()
{
    char chute;
    printf("Qual letra? ");
    scanf(" %c", &chute);
    chutes[total_de_chutes] = toupper(chute);
    total_de_chutes++;
}

int ja_foi_chutada(int i)
{
    int achou = 0;

    for (int j = 0; j < total_de_chutes; j++)
    {
        if (chutes[j] == palavrasecreta[i])
        {
            achou = 1;
            break;
        }
    }
    return achou;
}

void imprime_forca()
{
    int erros = total_erros();

    printf("  _______       \n");
    printf(" |/      |      \n");
    printf(" |      %c%c%c  \n", (erros >= 1 ? '(' : ' '), (erros >= 1 ? '_' : ' '), (erros >= 1 ? ')' : ' '));
    printf(" |      %c%c%c  \n", (erros >= 3 ? '\\' : ' '), (erros >= 2 ? '|' : ' '), (erros >= 3 ? '/' : ' '));
    printf(" |       %c     \n", (erros >= 2 ? '|' : ' '));
    printf(" |      %c %c   \n", (erros >= 4 ? '/' : ' '), (erros >= 4 ? '\\' : ' '));
    printf(" |              \n");
    printf("_|___           \n");
    printf("\n\n");

    for (size_t i = 0; i < strlen(palavrasecreta); i++)
    {
        int achou = ja_foi_chutada(i);

        if (achou)
        {
            printf("%c ", palavrasecreta[i]);
        }
        else
        {
            printf("_ ");
        }
    }
    printf("\n");
}

int contar_palavras(FILE *arquivo)
{
    int quantidade_de_palavras;
    fscanf(arquivo, "%d", &quantidade_de_palavras);
    return quantidade_de_palavras;
}

void ler_palavra(FILE *arquivo, int linha, char *palavrasecreta)
{
    for (int i = 0; i <= linha; i++)
    {
        if (fscanf(arquivo, "%s", palavrasecreta) != 1)
        {
            fprintf(stderr, "Error reading word from file\n");
            exit(EXIT_FAILURE);
        }
    }
}

void escolhe_palavra()
{
    FILE *arquivo = abrir_arquivo("r");

    int quantidade_de_palavras = contar_palavras(arquivo);

    srand(time(NULL));
    int linha_do_arquivo = rand() % quantidade_de_palavras;

    ler_palavra(arquivo, linha_do_arquivo, palavrasecreta);

    fclose(arquivo);
}

int total_erros()
{
    int erros = 0;

    for (int i = 0; i < total_de_chutes; i++)
    {
        int existe = 0;

        for (size_t j = 0; j < strlen(palavrasecreta); j++)
        {
            if (chutes[i] == palavrasecreta[j])
            {
                existe = 1;
                break;
            }
        }
        if (!existe)
        {
            erros++;
        }
    }
    return erros;
}

int enforcou()
{
    return total_erros() >= 5;
}

int acertou()
{
    for (size_t i = 0; i < strlen(palavrasecreta); i++)
    {
        if (!ja_foi_chutada(i))
        {
            return 0;
        }
    }
    return 1;
}

void mensagem_final()
{
    if (acertou())
    {
        printf("Parabéns! Você ganhou!\n");
        printf("       ___________      \n");
        printf("      '._==_==_=_.'     \n");
        printf("      .-\\:      /-.    \n");
        printf("     | (|:.     |) |    \n");
        printf("      '-|:.     |-'     \n");
        printf("        \\::.    /      \n");
        printf("         '::. .'        \n");
        printf("           ) (          \n");
        printf("         _.' '._        \n");
        printf("        '-------'       \n\n");

        adiciona_palavra();
    }
    else
    {
        printf("Você perdeu! A palavra era: %s\n", palavrasecreta);
        printf("    _______________         \n");
        printf("   /               \\       \n");
        printf("  /                 \\      \n");
        printf("//                   \\/\\  \n");
        printf("\\|   XXXX     XXXX   | /   \n");
        printf(" |   XXXX     XXXX   |/     \n");
        printf(" |   XXX       XXX   |      \n");
        printf(" |                   |      \n");
        printf(" \\__      XXX      __/     \n");
        printf("   |\\     XXX     /|       \n");
        printf("   | |           | |        \n");
        printf("   | I I I I I I I |        \n");
        printf("   |  I I I I I I  |        \n");
        printf("   \\_             _/       \n");
        printf("     \\_         _/         \n");
        printf("       \\_______/           \n");
    }
}

void atualiza_numero_de_palavras(FILE *arquivo)
{
    int quantidade_de_palavras = contar_palavras(arquivo);
    quantidade_de_palavras++;
    fseek(arquivo, 0, SEEK_SET);
    fprintf(arquivo, "%d\n", quantidade_de_palavras);
}

FILE *abrir_arquivo(char *modo)
{
    FILE *arquivo = fopen("palavras.txt", modo);
    if (arquivo == NULL)
    {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }
    return arquivo;
}

void adiciona_palavra()
{
    printf("Você que adicionar uma nova palavra: (S/N) ");
    char opcao;
    scanf(" %c", &opcao);

    if (toupper(opcao) == 'S')
    {
        FILE *arquivo = abrir_arquivo("r+");

        atualiza_numero_de_palavras(arquivo);

        char nova_palavra[20];
        printf("Digite a nova palavra: ");
        scanf("%s", nova_palavra);
        fseek(arquivo, 0, SEEK_END);
        fprintf(arquivo, "%s\n", nova_palavra);

        fclose(arquivo);
    }
    else
    {
        exit(EXIT_SUCCESS);
    }
}

int main()
{
    escolhe_palavra();

    do
    {
        imprime_forca();

        captura_chute();
    } while (!acertou() && !enforcou());

    mensagem_final();
}