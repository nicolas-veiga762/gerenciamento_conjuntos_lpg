#ifndef FUNCTIONS_H
#define FUNCTIONS_H

void inicializa_matriz(int m, int n, int matriz[m][n]);
int busca_valor(int conjunto[], int valor);
void inserir_valores(int m, int n, int matriz[m][n], int indice);
void remover_conjunto(int m, int n, int matriz[m][n], int indice);
void busca_por_valor(int m, int n, int matriz[m][n], int valor);

#endif