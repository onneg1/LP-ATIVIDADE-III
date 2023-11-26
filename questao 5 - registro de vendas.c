#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

// Desenvolva um programa que registre as vendas de uma loja, armazenando os valores em um vetor e apresentando o total de vendas ao final. Considere que cada venda precisa do nome de um produto, seu preço e sua quantidade. Crie um menu onde o usuário possa digitar o número 1 para adicionar uma venda e o número 2 para sair do menu e exibir o total das vendas realizadas.


int main() {
    setlocale(LC_ALL, "portuguese");

    //declarando variaveis.
    int op, contador = 0, qnt[100];
    char nome[100][3000];
    float preco[100];

    do {
        //laço do/while pedindo ao usuario para escolher entre adicionar um produto ou exibir o valor total das vendas descritas.
        printf("|1 - Adicionar uma venda                     |\n");
        printf("|2 - Exibir total de vendas realizadas       |\n");
        printf("Insira 1 ou 2: ");
        scanf("%d", &op);

        //criando dois cenarios para cada operacao escolhida, caso 1 e caso 2.
        switch (op) {
            case 1:
            //contador criado para ler quantas compras foram adicionadas.
                if (contador < 100) {
                    contador++;
                    printf("Informe o nome do produto: ");
                    fflush(stdin);
                    //gets para receber os nomes com o contador delimitando quantoes nomes existirão dentro do vetor, o mesmo para quantidade de produtos e preço dos mesmos.
                    gets(nome[contador]);

                    printf("Digite a quantidade do produto: ");
                    scanf("%d", &qnt[contador]);

                    printf("Digite o preço do produto: ");
                    scanf("%f", &preco[contador]);
                } else {
                    //caso o contador chegue em >=100, quantidade total de vendas excedido.
                    printf("Limite total de vendas excedido.\n");
                }
                //break para o codigo ser lido em suas devidas partes.
                break;
            case 2:
            //caso contador for maior que 0, e o usuario desejar exibir quantidade de produto e seus valores:
                if (contador > 0) {
                    //total de vendas se inicia com valor 0.
                    float totalVendas = 0;
                    //laço for para exibir ao usuario o produto, a quantidade comprada e seu valor.
                    for (int i = 1; i <= contador; i++) {
                        printf("PRODUTO: %s", nome[i]);
                        printf("QUANTIDADE DO PRODUTO: %d\n", qnt[i]);
                        printf("VALOR: %.2f\n", preco[i]);
                        //dando valor final ao total das vendas.
                        totalVendas += (qnt[i] * preco[i]);
                    }
                    //exibindo ao usuario o total de vendas.
                    printf("TOTAL DE VENDAS: %.2f\n", totalVendas);
                } else {
                    //caso o usuario escolha 2 e o contador for <= 0, nenhuma venda foi registrada.
                    printf("NENHUMA VENDA REGISTRADA.\n");
                }
                break;
            default:
            //caso usuario escolha algo diferente de 1 e 2, opção será invalida.
                if (op != 1 && op != 2) {
                    printf("Opcao invalida, digite 1 ou 2.\n");
                }
                break;
        }
        //repetir o laço do enquanto operação for igual a 1.
    } while (op == 1);

    return 0;
}