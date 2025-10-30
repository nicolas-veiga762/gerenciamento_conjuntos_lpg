#ifndef FUNCTIONS_H
#define FUNCTIONS_H


void inicializa_matriz(int m, int n, int matriz[m][n]);

int verifica_indice(int indice, int contador_conjuntos);

int criar_conjunto_vazio(int contador_conjuntos, int m);

void inserir_valores(int m, int n, int matriz[m][n], int indice, int contador_conjuntos);

void uniao_conjuntos(int m, int n, int matriz[m][n], int indice, int indice2, int contador_conjuntos);

void interseccao_conjuntos(int m, int n, int matriz[m][n], int indice, int indice2, int contador_conjuntos);

void mostrar_conjunto(int m , int n, int matriz[m][n], int indice);

void mostrar_todos_conjuntos(int m, int n, int matriz[m][n], int contador_conjuntos);

int busca_valor(int n, int conjunto[], int valor);

void remover_conjunto(int m, int n, int matriz[m][n], int contador_conjuntos, int indice);

void busca_por_valor(int m, int n, int matriz[m][n], int valor);

void limpa_tela();

void pausa();

void ordenar_conjuntos(int m, int n, int matriz[m][n]);

#endif