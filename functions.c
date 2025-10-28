#include <stdio.h>
#include "functions.h"
#include <stdlib.h>

#define M 10
#define N 10


// funções principais

void inicializa_matriz(int matriz[M][N]) {
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            matriz[i][j] = 0;
        }
    }
}

int verifica_indice(int indice, int contador_conjuntos) {
    return (indice >= 0 && indice < contador_conjuntos);
}


int criar_conjunto_vazio(int contador_conjuntos) {
    if (contador_conjuntos < M) {
        printf("Conjunto %d criado com sucesso!\n\n", contador_conjuntos);
        contador_conjuntos++;
    } else {
        printf("O limite maximo de conjuntos (%d) foi atingido.\nRemova um conjunto para criar outro.\n\n", M);
    }
    return contador_conjuntos;
}


void inserir_valores(int matriz[M][N], int indice) {
    int valor, j;

    // Encontra posição livre
    for (j = 0; j < N; j++) {
        if (matriz[indice][j] == 0) break;
    }

    if (j == N) {
        printf("O conjunto atingiu o limite de %d elementos.\n\n", N);
        return;
    }

    printf("Digite valores para o conjunto (digite 0 para parar):\n");
    for (int i = j; i < N; i++) {
        scanf("%d", &valor);
        if (valor == 0) break;
        if (busca_valor(N, matriz[indice], valor)) {
            printf("Valor '%d' ja existe! Digite outro:\n", valor);
            i--;
            continue;
        }
        matriz[indice][i] = valor;
    }

    // Zera posições não usadas
    for (int k = j; k < N; k++) {
        if (matriz[indice][k] == 0) continue;
    }

    limpa_tela();
    printf("Valores inseridos com sucesso!\n\n");
}

int remover_conjunto(int matriz[M][N], int indice, int contador_conjuntos) {
    if (contador_conjuntos == 0) {
        printf("Nao ha conjuntos para remover.\n\n");
        return contador_conjuntos;
    }

    if (!verifica_indice(indice, contador_conjuntos)) {
        printf("Indice invalido!\n\n");
        return contador_conjuntos;
    }

    // Move linhas abaixo do índice para cima
    for (int i = indice; i < contador_conjuntos - 1; i++) {
        for (int j = 0; j < N; j++) {
            matriz[i][j] = matriz[i + 1][j];
        }
    }

    // Zera a última linha
    for (int j = 0; j < N; j++) {
        matriz[contador_conjuntos - 1][j] = 0;
    }

    printf("Conjunto %d removido com sucesso!\n\n", indice);
    return contador_conjuntos - 1;
}

void uniao_conjuntos(int matriz[M][N], int indice1, int indice2, int contador_conjuntos) {
    int uniao[N * 2], k = 0, valor;
    int novo_indice = contador_conjuntos;

    for (int i = 0; i < N; i++) {
        if (matriz[indice1][i] == 0) break;
        uniao[k++] = matriz[indice1][i];
    }

    for (int j = 0; j < N; j++) {
        valor = matriz[indice2][j];
        if (valor == 0) break;
        if (!busca_valor(N * 2, uniao, valor)) {
            if (k >= N) {
                printf("A uniao ultrapassa o limite de %d elementos.\n\n", N);
                break;
            }
            uniao[k++] = valor;
        }
    }

    // Copia para a nova linha
    for (int i = 0; i < N; i++) {
        matriz[novo_indice][i] = (i < k) ? uniao[i] : 0;
    }

    printf("Conjunto uniao criado com indice %d.\n\n", novo_indice);
}

void interseccao_conjuntos(int matriz[M][N], int indice1, int indice2, int contador_conjuntos) {
    int interseccao[N], k = 0, valor;
    int novo_indice = contador_conjuntos;

    for (int i = 0; i < N; i++) {
        valor = matriz[indice1][i];
        if (valor == 0) break;
        if (busca_valor(N, matriz[indice2], valor)) {
            interseccao[k++] = valor;
        }
    }

    for (int i = 0; i < N; i++) {
        matriz[novo_indice][i] = (i < k) ? interseccao[i] : 0;
    }

    printf("Conjunto interseccao criado com indice %d.\n\n", novo_indice);
}

void mostrar_conjunto(int matriz[M][N], int indice) {
    printf("Conjunto %d = {", indice);
    for (int i = 0; i < N; i++) {
        if (matriz[indice][i] == 0) break;
        printf("%d", matriz[indice][i]);
        if (i < N - 1 && matriz[indice][i + 1] != 0) printf(", ");
    }
    printf("}\n\n");
}

void mostrar_todos_conjuntos(int m, int n, int matriz[m][n], int contador_conjuntos) {
    int i, j;
    printf("Todos os %i conjuntos criados:\n\n", contador_conjuntos);
    for(i = 0; i < contador_conjuntos; i++) {
        printf("Conjunto %i = {", i);
        for(j = 0; j < n; j++) {
            if (matriz[i][j] == 0) {
                break;
            }
            printf("%d", matriz[i][j]);
            if (j < n-1 && matriz[i][j+1] != 0) {
                printf(", ");
            }
        }
        printf("}\n");
    }
    printf("\n");
}

int busca_valor(int conjunto[N], int valor) {
    for (int i = 0; i < N; i++) {
        if (conjunto[i] == 0) break;
        if (conjunto[i] == valor) return 1;
    }
    return 0;
}


void busca_por_valor(int matriz[M][N], int valor, int contador_conjuntos) {
    int encontrado = 0;
    for (int i = 0; i < contador_conjuntos; i++) {
        for (int j = 0; j < N; j++) {
            if (matriz[i][j] == valor) {
                printf("Valor %d encontrado no conjunto %d.\n", valor, i);
                encontrado = 1;
                break;
            }
            if (matriz[i][j] == 0) break;
        }
    }
    if (!encontrado) {
        printf("Valor %d nao encontrado em nenhum conjunto.\n\n", valor);
    }
}

// funções opcionais

void limpa_tela() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

#ifdef _WIN32
#include <windows.h>
#define sleep_ms(ms) Sleep(ms)
#else
#include <unistd.h>
#define sleep_ms(ms) usleep(ms * 1000)
#endif

void pausa() {
    printf("Carregando");
    for (int i = 0; i < 3; i++) {
        printf(".");
        fflush(stdout);
        sleep_ms(500);
    }
    printf("\n");
}

void ordenarConjunto(int conjunto[N]) {
    int i, j, aux;
    int tamanho = 0;

    // Descobre quantos elementos válidos há (para ignorar zeros)
    for (i = 0; i < N; i++) {
        if (conjunto[i] == 0) break;
        tamanho++;
    }

    // Ordena apenas os elementos válidos (Bubble Sort)
    for (i = 0; i < tamanho - 1; i++) {
        for (j = 0; j < tamanho - i - 1; j++) {
            if (conjunto[j] > conjunto[j + 1]) {
                aux = conjunto[j];
                conjunto[j] = conjunto[j + 1];
                conjunto[j + 1] = aux;
            }
        }
    }

    printf("Conjunto ordenado com sucesso!\n\n");
}
