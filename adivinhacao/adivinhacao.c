#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void apresentacao(void)
{
    printf("********************************\n");
    printf("Bem vindo ao jogo de adivinhação\n");
    printf("********************************\n");
}

int selecao_dificuldade(void)
{
    int chances;
    char dificuldade;

    printf("Escolha a dificuldade: 'f' (fácil), 'm' (médio), 'd' (difícil): ");
    scanf(" %c", &dificuldade);

    switch (dificuldade)
    {
    case 'f':
        chances = 9;
        break;
    case 'm':
        chances = 7;
        break;
    case 'd':
        chances = 5;
        break;
    default:
        chances = 7;
        break;
    }
    return chances;
}

int subtrai_pontos(int chute, int numero_secreto)
{
    return abs((chute - numero_secreto) / 2.0);
}

void verifica_chute(int chances)
{
    srand(time(NULL));
    int numero_secreto = rand() % 100;
    int acertou = 0;
    int chute;
    int pontos = 1000;
    printf("%d", numero_secreto);

    while (!acertou && chances > 0)
    {
        printf("Chute um número: ");
        scanf("%d", &chute);

        if (chute == numero_secreto)
        {
            printf("Você acertou!!!, %d era o número secreto.\n", chute);
            printf("Você fez %d pontos\n", pontos);
            acertou = 1;
        }
        else if (chute > numero_secreto)
        {
            printf("%d é maior que o número secreto.\n", chute);
        }
        else
        {
            printf("%d era menor que o número secreto.\n", chute);
        }
        chances--;
        pontos -= subtrai_pontos(chute, numero_secreto);
    }

    if (chances == 0)
    {
        printf("Não foi dessa vez. O número secreto era %d\n", numero_secreto);
    }
}

int main(void)
{
    apresentacao();
    int chances = selecao_dificuldade();
    verifica_chute(chances);
    printf("Fim do jogo\n");
    return 0;
}