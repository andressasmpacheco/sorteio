#include <stdio.h>
#include <time.h>

int random();
void dicas(int num, int senha, int tentativa);

int main()
{
    int continuar=1,
        senha,
        tentativa,
        num;

    do
    {
        system("cls || clear");
        printf("Sorteando numero entre 1 e 100...\n");
        senha = random();

        printf("Comecou! Tente adivinhar o numero!\n\n");
        tentativa = 0;

        do
        {
            tentativa++;
            printf("Tentativa %d: ", tentativa);
            scanf("%d", &num);
            dicas(num,senha,tentativa);
        }
        while( num != tentativa);

        printf("Digite 0 para sair, ou qualquer outro numero para continuar: ");
        scanf("%d", &continuar);
    }
    while(continuar);

}

int random()
{
    srand( (unsigned)time(NULL) );

    return (1 + rand()%100);
}

void dicas(int num, int senha, int tentativa)
{
    if(num > senha)
                printf("O numero sorteado e menor que %d\n\n", num);
    else
        if(num < senha)
            printf("O numero sorteado e maior que %d\n\n", num);
        else
            printf("Parabens! Voce acertou o numero em %d tentativas!\n\n", tentativa);
}
