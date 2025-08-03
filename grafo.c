#include <stdio.h>
#include "grafo.h"

void inicializaGrafo(int grafo[MAX][MAX], int n) {
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            grafo[i][j] = (i == j) ? 0 : INF;
}

void leGrafo(int grafo[MAX][MAX], int m) {
    int u, v, w;
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &u, &v, &w);
        if (w < grafo[u][v]) {
            grafo[u][v] = w;
            grafo[v][u] = w;
        }
    }
}
