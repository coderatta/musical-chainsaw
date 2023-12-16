#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int ganhou()
{
    return 0;
}

int enforcou()
{
    return 0;
}

/*
int sorteia_palavra()
{
    int quantidade_de_palavras = sizeof(palavras) / sizeof(palavras[0]);
    srand(time(NULL));
    int indice_da_palavra = rand() % quantidade_de_palavras;
    return palavras[indice_da_palavra];
}
 */

int main(void)
{
    char palavra_secreta[20];
    sprintf(palavra_secreta, "LION");
    char letras_chutadas[26];
    int tentativas = 0;

    do
    {
        for (size_t i = 0; i < strlen(palavra_secreta); i++)
        {
            for (size_t j = 0; j < tentativas; j++)
            {
                if (palavra_secreta[i] == letras_chutadas[j])
                {
                    printf("%c ", palavra_secreta[i]);
                    break;
                }
            }
            printf("_ ");
        }
        printf("\n");

        printf("Chuta aí: ");
        char chute;
        scanf(" %c", &chute);
        letras_chutadas[tentativas] = chute;

        for (size_t i = 0; i < strlen(palavra_secreta); i++)
        {
            if (chute == palavra_secreta[i])
            {
                printf("Acertou\n");
                tentativas--;
            }
            else
            {
                printf("Errou\n");
                tentativas++;
            }
        }

    } while (!ganhou() && !enforcou());

    return 0;
}