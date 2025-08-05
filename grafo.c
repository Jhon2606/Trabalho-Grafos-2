#include <stdio.h>
#include "grafo.h"

void inicializaGrafo(int grafo[MAX][MAX], int n) {
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            grafo[i][j] = (i == j) ? 0 : INF;
}

void lerGrafo(int grafo[MAX][MAX], int m) {
    int cidade1, cidade2, tamanho_estrada;
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &cidade1, &cidade2, &tamanho_estrada);
        if (tamanho_estrada < grafo[cidade1][cidade2]) {
            grafo[cidade1][cidade2] = tamanho_estrada;
            grafo[cidade2][cidade1] = tamanho_estrada;
        }
    }
}
