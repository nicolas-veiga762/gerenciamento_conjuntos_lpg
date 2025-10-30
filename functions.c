#include <stdio.h>
#include "functions.h"
#include <stdlib.h>

// Inicializa a matriz com zeros
void inicializa_matriz(int m, int n, int matriz[m][n]) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            matriz[i][j] = 0;
        }
    }
}

// Verifica se o índice já extrapolou o limite do tamanho da matriz
int verifica_indice(int indice, int contador_conjuntos) {
    if(indice < contador_conjuntos && indice >= 0) {
        return 1;
    } else {
        return 0;
    }
}

// Cria um conjunto vazio para possibilitar a inserção de dados
int criar_conjunto_vazio(int contador_conjuntos, int m) {
    if(contador_conjuntos < m) {
        contador_conjuntos++;
    } else {
        printf("O tamanho maximo da matriz foi atingido, nao e possivel criar mais conjuntos.\nCaso queira criar um novo conjunto, e necessario remover algum outro para abrir espaco.\n\n");
    }
    return contador_conjuntos;
}

// Função para inserção de valores em um conjunto
void inserir_valores(int m , int n, int matriz[m][n], int indice, int contador_conjuntos) {
    int i, j, valor;
    for(j = 0; j < n; j++) {
        if(matriz[indice][j] == 0) {
            break;
        }
    }
    if(j == n) {
        printf("O tamanho maximo do conjunto foi atingido.\n\n");
    } else {
        printf("Digite ate %i valores para o conjunto ou digite 0 para parar quando desejar:\n", n-j);
        for(i = j; i < n; i++) {
            scanf("%d", &valor);
            if(valor == 0) {
                limpa_tela();
                printf("Valores inseridos com sucesso!\n\n");
                break;
            }
            if (busca_valor(n, matriz[indice], valor)) {
                printf("Valor '%i' ja existe no conjunto! Digite outro valor:\n", valor);
                i--;
                continue;
            }
            matriz[indice][i] = valor;
        }
        limpa_tela();
        pausa();
        printf("Valores inseridos com sucesso!\n\n");
    }
    contador_conjuntos++;
}

// Remove um conjunto e realoca os outros existentes
void remover_conjunto(int m, int n, int matriz[m][n], int contador_conjuntos, int indice) {
    int i, j;
    for (i = indice; i < contador_conjuntos; i++) {
        for (int j = 0; j < n; j++) {
            matriz[i][j] = matriz[i + 1][j];
        }
    }
    for (j = 0; j < n; j++) {
        matriz[contador_conjuntos][j] = 0;
    }
    pausa();
    limpa_tela();
    printf("Conjunto %d removido com sucesso!\n\n", indice);
}

// Cria um conjunto resultante da união de outros dois
void uniao_conjuntos(int m, int n, int matriz[m][n], int indice, int indice2, int contador_conjuntos) {
    int i, j, k = 0, valor, uniao[n+n], novo_indice;
    for(i = 0; i < n; i++) {
        if (matriz[indice][i] == 0) {
            break;
        }
        uniao[k++] = matriz[indice][i];
    }
    for(j = 0; j < n; j++) {
        valor = matriz[indice2][j];
        if(valor == 0) {
            break;
        }
        if(!busca_valor(n+n, uniao, valor)) {
            if (k < n) {
                uniao[k] = valor;
                k++;
            } else {
                pausa();
                printf("Nao e possivel criar o conjunto uniao pois a uniao ultrapassa o tamanho limite de conjuntos.\n\n");
                break;
            }
            
        }
    }
    novo_indice = contador_conjuntos;
    for (i = 0; i < n; i++) {
        if (i < k) {
            matriz[novo_indice][i] = uniao[i];
        }
        else {
            matriz[novo_indice][i] = 0;
        }
    }
}

// Cria um conjunto resultante da intersecção de outros dois
void interseccao_conjuntos(int m, int n, int matriz[m][n], int indice, int indice2, int contador_conjuntos) {
    if (contador_conjuntos >= m) {
        pausa();
        printf("Nao ha espaco suficiente na matriz para armazenar o conjunto interseccao.\n\n");
        return;
    }
    
    int j = 0, interseccao[n], novo_indice;
    for(int i = 0; i < n; i++) {
        if(busca_valor(n, matriz[indice], matriz[indice2][i])) {
            interseccao[j] = matriz[indice2][i];
            j++;
        }
    }
    for (int i = j; i < n; i++) {
        interseccao[i] = 0;
    }
    novo_indice = contador_conjuntos;
    for (int i = 0; i < n; i++) {
        if (i < j) {
            matriz[novo_indice][i] = interseccao[i];
        }
        else {
            matriz[novo_indice][i] = 0;
        }
    }
    pausa();
}

// Mostra apenas um conjunto escolhido pelo usuário
void mostrar_conjunto(int m , int n, int matriz[m][n], int indice) {
    pausa();
    int i;
    printf("Conjunto de indice %i:\n\n", indice);
    printf("{");
    for(i = 0; i < n; i++) {
        if (matriz[indice][i] == 0) {
            break;
        }
        printf("%d", matriz[indice][i]);
        if (i < n-1 && matriz[indice][i+1] != 0) {
            printf(", ");
        }
    }
    printf("}\n\n");
}

// Mostra todos os conjuntos criados
void mostrar_todos_conjuntos(int m, int n, int matriz[m][n], int contador_conjuntos) {
    pausa();
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

// Busca por um valor em um conjunto e retorna verdeira ou falso (função auxiliar)
int busca_valor(int n, int conjunto[], int valor) {
    for (int i = 0; i < n; i++) {
        if (conjunto[i] == valor) {
            return 1;
        }
        if (conjunto[i] == 0) {
            break;
        }
    }
    return 0;
}

// Função que busca um valor específico e retorna ao usuário em que conjuntos esse valor aparece
void busca_por_valor(int m, int n, int matriz[m][n], int valor) {
    pausa();
    int encontrou = 0, i, j;
    if(valor == 0) {
        encontrou = 0;
    } else {
        for (i = 0; i < m; i++) {
            for (j = 0; j < n; j++) {
                if (matriz[i][j] == valor) {
                    printf("Conjunto(s) com o valor:\n\n");
                    printf("O conjunto %i possui o elemento %i.\n\n", i, valor);
                    encontrou = 1;
                    break;
                }
            }
        }
    }
    if (!encontrou) {
        printf("Nenhum conjunto possui o valor %i.\n\n", valor);
    }
}

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
    limpa_tela();
}