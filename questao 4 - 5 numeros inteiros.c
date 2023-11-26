#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

//Crie um software que leia 5 números inteiros e, em seguida, mostre na tela:
//A quantidade de números ímpares;
//A quantidade de números negativos;
//O maior e o menor número;
//A média de números pares;
//A média de números inseridos.

int main(){
    setlocale(LC_ALL, "portuguese");

    int num[5];
    int neg = 0, impar = 0, par = 0;
    int somanum = 0;
    float media = 0;
    int i;
    int maiornum = 0, menornum = 99999;
    float mediapares = 0, somapares = 0;
    ;

    // for para solicitar os 5 dados ao usuario.
    for (i = 0; i < 5; i++)
    {
        printf("Digite o %d numero inteiro:\n", i + 1);
        scanf("%d", &num[i]);
        // fazendo a soma dos numeros.
        somanum += num[i];
        // criando contador adicionando 1 em caso de numero negativo (menor que zero).
        num[i] < 0 ? neg++ : 0;
        // verificando se o numero é par, criando contador adicionando 1 em caso de numero par, e 1 em caso de numero impar.
        num[i] % 2 != 0 ? impar++ : (somapares += num[i], par++);

        // vendo qual o maior e o menor numero.
        num[i] > maiornum ? maiornum = num[i] : 0;
        num[i] < menornum ? menornum = num[i] : 0;
    }
    // fazendo a media artimetica dos numeros totais e dos numeros pares.
    media = somanum / i;
    mediapares = somapares / par++;
    // printf para mostrar ao usuario as informacoes.
    printf("\tA quantidade de numeros impares: %d;\n", impar);
    printf("\tA quantidade de numeros negativos: %d;\n", neg);
    printf("\tMaior numero: %d; \n\tMenor numero: %d;\n", maiornum, menornum);
    printf("\tA media dos numeros pares: %.1f;\n", mediapares);
    printf("\tA media dos numeros inseridos: %.1f;\n", media);

    return 0;
}