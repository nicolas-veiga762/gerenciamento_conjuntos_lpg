#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#define M 10
#define N 10

int verifica_indice(int indice, int contador_conjuntos);
int criar_conjunto_vazio(int contador_conjuntos);

int busca_valor(int conjunto[N], int valor);
void limpa_tela();
void pausa();
void ordenarConjunto(int conjunto[N]);

void inicializa_matriz(int matriz[M][N]);
void inserir_valores(int matriz[M][N], int indice);
int remover_conjunto(int matriz[M][N], int indice, int contador_conjuntos);
void uniao_conjuntos(int matriz[M][N], int indice1, int indice2, int contador_conjuntos);
void interseccao_conjuntos(int matriz[M][N], int indice1, int indice2, int contador_conjuntos);
void mostrar_conjunto(int matriz[M][N], int indice);
void mostrar_todos_conjuntos(int matriz[M][N], int contador_conjuntos);
void busca_por_valor(int matriz[M][N], int valor, int contador_conjuntos);

#endif