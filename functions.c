#include <stdio.h>
#include "functions.h"

void inicializa_matriz(int matriz[][]) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            mat[i][j] = 0;
        }
    }
}

int busca_valor(int conjunto[n], int valor) {
    for (int i = 0; i < n; i++) {
        if (conjunto[i] == valor) {
            return 1;
        }
    }
    return 0;
}

void inserir_valores(matriz[m][n], int indice) {
    printf("Digite a seguir os valores do seu novo conjunto:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", matriz[indice][i]);
    }
}

void remover_conjunto(matriz[m][n], int indice) {
    for (int i = 0; i < n; i++) {
        mat[indice][i] = 0;
    }
}

void busca_por_valor(int matriz[m][n], int valor) {
    int conjunto = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; i < n; j++) {
            if (mat[i][j] == valor) {
                conjunto = j;
                printf("O conjunto %i possui o valor %i", conjunto, valor);
            }
        }
    }
}