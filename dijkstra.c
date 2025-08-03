#include <limits.h>
#include "dijkstra.h"

int dijkstra(int grafo[MAX][MAX], int n, int origem, int destino, int proibidas[MAX]) {
    int dist[MAX];
    int visitado[MAX] = {0};

    for (int i = 1; i <= n; i++)
        dist[i] = INF;

    dist[origem] = 0;

    for (int count = 0; count < n; count++) {
        int u = -1;
        int menorDist = INF;

        for (int i = 1; i <= n; i++) {
            if (!visitado[i] && dist[i] < menorDist) {
                menorDist = dist[i];
                u = i;
            }
        }

        if (u == -1) break;
        visitado[u] = 1;

        for (int v = 1; v <= n; v++) {
            if (grafo[u][v] != INF && !visitado[v]) {
                if (proibidas[v] && v != destino) continue;
                if (proibidas[u] && u != origem) continue;

                if (dist[u] + grafo[u][v] < dist[v])
                    dist[v] = dist[u] + grafo[u][v];
            }
        }
    }
    return dist[destino];
}
