#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

// Crie um programa que faça o cadastro de 5 alunos em uma escola, armazenando seus dados como: nome, idade e  3 notas  para cada aluno. Ao final, mostre todos os dados dos alunos como: nome, idade, as notas e a média. Após calcular a média, verifique para cada aluno se este estará aprovado (média maior ou igual a 7,0), em recuperação (média menor que 7,0 e maior ou igual a 5,0) ou reprovado (média menor que 5,0) com base nestes critérios.

int main(){
    setlocale(LC_ALL, "portuguese");
    //declarando variaveis.
    int i=0, j=0;
    int idade[5];
    char nome[5][250];
    float nota[5][3]={0}, somanota[5]={0}, mediatotal[5]={0};

    for (i = 0; i < 5; i++){
        //pedindo nome e idade dos alunos.
        printf("Digite o nome do %d aluno:\n", i + 1);
        gets(nome[i]);
        
        printf("Digite a idade de %s:\n", nome[i], i + 1);
        scanf("%d", &idade[i]);
        
        for (j = 0; j < 3; j++){
            //matriz para adicionar as 3 notas de cada aluno dentro do vetor nota.
            printf("Digite a %d nota de %s:\n", j + 1, nome[i]);
            scanf("%f", &nota[i][j]);
        //criando a soma de todas as notas.
            somanota[i] += nota[i][j];
        }
        fflush (stdin); 
        //media é = a toda a soma das notas dividido por j.
        mediatotal[i] = somanota[i] / j;
    }
    //for para apresentar nome, idade, notas e media de cada aluno.
    for (i = 0; i < 5; i++)
    { 
        printf("\t\nNome do %d aluno:%s\n", i + 1, nome[i]);
        printf("\t\nIdade do %d aluno:%d\n", i + 1, idade[i]);
        for (j = 0; j < 3; j++)
        {
         printf("\t\n%d nota de %s:%.1f\n", j+1, nome[i], nota[i][j]);
        }
        printf("\t\bMedia de %s:%.2f\n", nome[i], mediatotal[i]);

    //verificando aprovação do aluno.
        mediatotal[i] >= 7.0 ? printf("APROVADO\n"): 0;
        mediatotal[i] >= 5.0 && mediatotal[i] <= 6.9 ? printf("RECUPERAÇÃO\n"): 0;
        mediatotal[i] <= 4.9 ? printf("REPROVADO\n"): 0;
    }

    return 0;
}