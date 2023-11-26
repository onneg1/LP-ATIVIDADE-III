#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

// Implemente um programa que permita cadastrar contatos telefônicos em uma agenda, utilizando vetores para armazenar os nomes e números de telefone. Permita que o usuário digite o código 1 para adicionar um número e 2 para mostrar os números cadastrados e encerrar o software.

//declarando variaveis
int contador=0, cod, i;
char nome[100][3000];
char num[100][250];


int main (){
        setlocale(LC_ALL, "portuguese");
        //instruindo ao codigo a repeticao de toda linha do caso o usuario digite 1.
        do {
            //solicitando os dados ao usuario
            printf ("Digite 1 para adicionar um numero: \n");
            printf ("Digite 2 para mostrar os numeros adicionados:\n");
            scanf ("%d", &cod);
            //usasse um fflush para limpar qualquer tipo de cache que possa existir no sistema
            fflush (stdin);

            //switch para direcionar o programa a leitura da opcao 1 e da opcao 2.
            switch (cod){
                case 1: 
                //caso usuario digite 1, verifique se o contador está menor que 100, se sim, adicione um novo numero e um novo nome, e adicione tambem +1 ao contador.
                if (contador < 100){
                    printf ("\tDigite o nome:\n");
                    gets (nome[contador]);
                    fflush (stdin);
                    printf ("\tDigite o numero:\n");
                    gets (num[contador]);
                    fflush (stdin);
                    contador++;
                } else {
                    //se o contador estiver maior que 100, numero de telefones e nomes excedido.
                    printf ("Maximo de numeros atingido.\n");
                }
                //break para leitura em partes do switch.
                break;

                case 2: 
                //caso usuario escolha opcao 2, verifique se o contador é maior que 0, se sim, mostre as informações para o usuario com um laço for.
                if (contador > 0) {
                    //o laço for irá de 0, até o numero de contadores adicionado lá em cima, de 1 em 1.
                    for (i = 0; i < contador; i++){
                        //mostre ao usuario os nomes e numero existentes nos vetores num[i] e nome[i].
                        printf ("\t\n%d nome: %s", i+1, nome[i]);
                        printf ("\t\n%d numero: %s", i+1, num[i]);
                    }
                } else {
                    //se contador for menor que 0, nenhum telefone foi registrado.
                    printf ("Nenhum telefone registrado!\n");
                }
                break;
                //caso nao seja escolhido nem a opcao 1 nem a 2, mostre opcao invalida.
                default: 
                if (cod != 1 && cod != 2){
                    printf ("Opcao invalida, escolha opcao 1 ou 2.");
                }
                break;
            
            }
            //repita tudo enquanto a variavel cod for 1.
        } while (cod == 1);


    return 0;
}