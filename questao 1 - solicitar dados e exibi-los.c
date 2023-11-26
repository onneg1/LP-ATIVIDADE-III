#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

// Crie um algoritmo que leia o nome, a idade, o peso e a altura de 5 pessoas, armazenando em vetores.
//- Mostre as informações solicitadas de cada pessoa e informe:
// O nome e a altura da pessoa mais alta e a mais baixa.
// O nome e o peso da pessoa com maior peso e menor peso;
// O nome a idade da pessoa com mais idade e com menos idade.

int main()
{
    setlocale(LC_ALL, "portuguese");

    char nome[5][250];
    int idade[5], i;
    float peso[5];
    float altura[5];
    float maioraltura = 1;
    char nomemaioraltura[250];
    float menoraltura = 3;
    char nomemenoraltura[250];
    float maiorpeso = 0;
    char nomemaiorpeso[250];
    float menorpeso = 999999;
    char nomemenorpeso[250];
    int maioridade = 0;
    char nomemaioridade[250];
    int menoridade = 999999;
    char nomemenoridade[250];

    //for para solicitar os dados ao usuario
    for (i = 0; i < 5; i++){
        printf("Digite o %d nome: \n", i + 1);
        gets(nome[i]);

        printf("Digite a idade de %s: \n", nome[i]);
        scanf("%d", &idade[i]);

        printf("Digite o peso de %s: \n", nome[i]);
        scanf("%f", &peso[i]);

        printf("Digite a altura de %s: \n", nome[i]);
        scanf("%f", &altura[i]);

        fflush(stdin);
        system ("clear || cls");

        //operadores ternarios para fazer a validação de todos dados solicitados pela questao, após, um strcpy para dar nome aos maiores e menores de cada dado solicitado, devem exisitir formas mais simples porem foi a pensada no momento, há o que melhorar.
        altura[i] > maioraltura ? maioraltura = altura[i], strcpy(nomemaioraltura, nome[i]) : 0;
        altura[i] < menoraltura ? menoraltura = altura[i], strcpy(nomemenoraltura, nome[i]) : 0;
        peso[i] > maiorpeso ? maiorpeso = peso[i], strcpy(nomemaiorpeso, nome[i]) : 0;
        peso[i] < menorpeso ? menorpeso = peso[i], strcpy(nomemenorpeso, nome[i]) : 0;
        idade[i] > maioridade ? maioridade = idade[i], strcpy(nomemaioridade, nome[i]) : 0;
        idade[i] < menoridade ? menoridade = idade[i], strcpy(nomemenoridade, nome[i]) : 0;
    }

    //for para exibir os dados aos usuarios.
    for (i = 0; i < 5; i++)
    {
        printf("\t %d Nome: %s\n", i + 1, nome[i]);
        printf("\t Idade de %s: %d\n", nome[i], idade[i]);
        printf("\t Peso de %s: %.1f\n", nome[i], peso[i]);
        printf("\t Altura de %s: %.1f\n", nome[i], altura[i]);
    }
    //printf para mostrar os maiores e menores e seus respectivos nomes.
    printf("\t\n A maior altura foi a de %s: %.1f \n", nomemaioraltura, maioraltura);
    printf("\t\n A menor altura foi a de %s: %.1f \n", nomemenoraltura, menoraltura);
    printf("\t\n O maior peso foi o de %s: %.1f \n", nomemaiorpeso, maiorpeso);
    printf("\t\n O menor peso foi o de %s: %.1f \n", nomemenorpeso, menorpeso);
    printf("\t\n A maior idade foi a de %s: %d \n", nomemaioridade, maioridade);
    printf("\t\n A menor idade foi a de %s: %d \n", nomemenoridade, menoridade);

    return 0;
}