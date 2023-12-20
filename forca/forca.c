#include <stdio.h>
#include <string.h>
#include <ctype.h>

char palavrasecreta[20];
char chutes[26];
int tentativas = 0;

void captura_chute()
{
    char chute;
    printf("Qual letra? ");
    scanf(" %c", &chute);
    chutes[tentativas] = toupper(chute);
    tentativas++;
}

int verifica_se_letra_ja_foi_chutada(int i)
{
    int achou = 0;

    for (int j = 0; j < tentativas; j++)
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

int main()
{
    escolhe_palavra();

    int acertou = 0;
    int enforcou = 0;

    do
    {
        imprime_forca();

        captura_chute();
    } while (!acertou && !enforcou);
}