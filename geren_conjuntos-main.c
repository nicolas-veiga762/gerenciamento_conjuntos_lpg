#include <stdio.h>
#include <math.h>
#include "functions.h"
#include <stdlib.h>

int main (void) {
    int m, n, opcao, indice, indice2, valor;
    printf("Digite o numero de linhas da matriz: ");
    scanf("%i", &m);
    printf("Digite o numero de colunas da matriz: ");
    scanf("%i", &n);

    int matriz[m][n], contador_conjuntos = 0;
    inicializa_matriz(m, n, matriz);
    limpa_tela();

    do {
        printf("------ GERENCIAMENTO DE CONJUNTOS ------\n\n");
        printf("1 - Criar um novo conjunto vazio.\n");
        printf("2 - Inserir dados em um conjunto.\n");
        printf("3 - Remover um conjunto.\n");
        printf("4 - Fazer a uniao entre dois conjuntos.\n");
        printf("5 - Fazer a interseccao entre dois conjuntos.\n");
        printf("6 - Mostrar um conjunto.\n");
        printf("7 - Mostrar todos os conjuntos.\n");
        printf("8 - Fazer busca por um valor.\n");
        printf("9 - Ordenar conjuntos.\n");
        printf("10 - Sair do programa.\n\n");
        printf("Escolha uma opcao: ");
        scanf("%i", &opcao);
        limpa_tela();

        switch (opcao) {
        case 1:
            contador_conjuntos = criar_conjunto_vazio(contador_conjuntos, m);
            break;
        case 2:
            printf("Digite o indice do conjunto em que deseja inserir os dados: ");
            scanf("%i", &indice);
            limpa_tela();
            if(verifica_indice(indice, contador_conjuntos)) {
                inserir_valores(m, n, matriz, indice, contador_conjuntos);
            } else {
                printf("O indice digitado nao corresponde a nenhum conjunto existente.\n\n");
            }
            break;
        case 3:
            printf("Digite o indice do conjunto que deseja remover: ");
            scanf("%i", &indice);
            limpa_tela();
            remover_conjunto(m, n, matriz, contador_conjuntos, indice);
            break;
        case 4:
            printf("Digite o indice do primeiro conjunto: ");
            scanf("%i", &indice);
            printf("Digite o indice do segundo conjunto: ");
            scanf("%i", &indice2);
            limpa_tela();
            if(verifica_indice(indice, contador_conjuntos) && verifica_indice(indice2, contador_conjuntos)) {
                uniao_conjuntos(m, n, matriz, indice, indice2, contador_conjuntos);
                contador_conjuntos = criar_conjunto_vazio(contador_conjuntos, m);
            } else {
                printf("Algum dos indices digitados nao corresponde a um conjunto existente.\nTente novamente com outros indices.\n\n");
            }
            break;
        case 5:
            printf("Digite o indice do primeiro conjunto: ");
            scanf("%i", &indice);
            printf("Digite o indice do segundo conjunto: ");
            scanf("%i", &indice2);
            limpa_tela();
            if(verifica_indice(indice, contador_conjuntos) && verifica_indice(indice2, contador_conjuntos)) {
                interseccao_conjuntos(m, n, matriz, indice, indice2, contador_conjuntos);
                contador_conjuntos = criar_conjunto_vazio(contador_conjuntos, m);
            } else {
                printf("Algum dos indices digitados nao corresponde a um conjunto existente.\nTente novamente com outros indices.\n\n");
            }
            break;
        case 6:
            printf("Digite o indice do conjunto que voce deseja analisar: ");
            scanf("%i", &indice);
            limpa_tela();
            if(verifica_indice(indice, contador_conjuntos)) {
                mostrar_conjunto(m, n, matriz, indice);
            } else {
                printf("O indice digitado nao corresponde a nenhum conjunto existente.\n\n");
            }
            break;
        case 7:
            mostrar_todos_conjuntos(m, n, matriz, contador_conjuntos);
            break;
        case 8:
            printf("Digite o valor que deseja buscar nos conjuntos: ");
            scanf("%i", &valor);
            busca_por_valor(m, n, matriz, valor);
            break;
        case 9:
            ordenar_conjuntos(m, n, matriz);
        }
    } while (opcao != 10);
}