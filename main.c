#include <stdio.h>
#include <stdlib.h>
#include "grafo.h"
#include "dijkstra.h"

int main() {
    int n, m;
    int grafo[MAX][MAX];

    FILE *grafoFile = freopen(NULL, "r", stdin);
    scanf("%d %d", &n, &m);

    inicializaGrafo(grafo, n);
    lerGrafo(grafo, m);

    freopen("/dev/tty", "r", stdin);

    int origem, destino, numProibidas;

    while (printf("\nDigite a origem, destino e o numero de cidades proibidas\n"),
           scanf("%d %d %d", &origem, &destino, &numProibidas) == 3) {

        int proibidas[MAX] = {0};
        for (int i = 0; i < numProibidas; i++) {
            int cidade = n - i;
            proibidas[cidade] = 1;
        }

        int resultado = dijkstra(grafo, n, origem, destino, proibidas);

        if (resultado == INF)
            printf("YL NÃO PODERÁ REALIZAR ESTA VIAGEM\n");
        else
            printf("%d\n", resultado);
    }

    return 0;
}
