#include <limits.h>
#include "dijkstra.h"

int dijkstra(int grafo[MAX][MAX], int n, int origem, int destino, int proibidas[MAX]) {
    int dist[MAX];
    int pred[MAX];
    int visitado[MAX] = {0};

    for (int i = 1; i <= n; i++) {
        dist[i] = INF;
        pred[i] = -1;
    }

    dist[origem] = 0;

    for (int count = 0; count < n; count++) {
        int cidadeAtual = -1;
        int menorDist = INF;

        for (int i = 1; i <= n; i++) {
            if (!visitado[i] && dist[i] < menorDist) {
                menorDist = dist[i];
                cidadeAtual = i;
            }
        }

        if (cidadeAtual == -1) break;
        visitado[cidadeAtual] = 1;

        for (int cidadeVizinha = 1; cidadeVizinha <= n; cidadeVizinha++) {
            if (grafo[cidadeAtual][cidadeVizinha] != INF && !visitado[cidadeVizinha]) {
                if (proibidas[cidadeVizinha] && cidadeVizinha != destino) continue;
                if (proibidas[cidadeAtual] && cidadeAtual!= origem) continue;

                if (dist[cidadeAtual] + grafo[cidadeAtual][cidadeVizinha] < dist[cidadeVizinha]) {
                    dist[cidadeVizinha] = dist[cidadeAtual] + grafo[cidadeAtual][cidadeVizinha];
                    pred[cidadeVizinha] = cidadeAtual;
                }
            }
        }
    }
    
    return dist[destino];
}