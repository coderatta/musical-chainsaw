#include <stdio.h>
#include <string.h>
#include <ctype.h>

char palavrasecreta[20];
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

int verifica_se_letra_ja_foi_chutada(int i)
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
    for (size_t i = 0; i < strlen(palavrasecreta); i++)
    {
        int achou = verifica_se_letra_ja_foi_chutada(i);

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

void escolhe_palavra()
{
    sprintf(palavrasecreta, "MELANCIA");
}

int enforcou()
{
    int erros = 0;

    for (size_t i = 0; i < total_de_chutes; i++)
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
    return erros >= 5;
}

int acertou()
{
}

int main()
{
    escolhe_palavra();

    do
    {
        imprime_forca();

        captura_chute();
    } while (!acertou() && !enforcou());
}