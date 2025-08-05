#include <stdio.h>
#include <stdlib.h>
#include "grafo.h"
#include "dijkstra.h"

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Uso: %s nome_do_arquivo.txt\n", argv[0]);
        return 1;
    }

    FILE *arquivo = fopen(argv[1], "r");
    if (arquivo == NULL) {
        perror("Erro ao abrir o arquivo");
        return 1;
    }

    int n, m;
    fscanf(arquivo, "%d %d", &n, &m);

    int grafo[MAX][MAX];
    inicializaGrafo(grafo, n);
    
    lerGrafo(grafo, m, arquivo);
    fclose(arquivo);

    int origem, destino, numProibidas;

while (1) {
    printf("\nInsira a cidade de origem: ");
    if (scanf("%d", &origem) != 1) break;

    printf("Insira a cidade de destino: ");
    if (scanf("%d", &destino) != 1) break;

    printf("Insira a quantidade de cidades proibidas: ");
    if (scanf("%d", &numProibidas) != 1) break;

    int proibidas[MAX] = {0};
    for (int i = 0; i < numProibidas; i++) {
        int cidade = n - i;
        proibidas[cidade] = 1;
    }

    int resultado = dijkstra(grafo, n, origem, destino, proibidas);

    if (resultado == INF)
        printf("YL NÃO PODERÁ REALIZAR ESTA VIAGEM\n");
    else
        printf("Menor caminho: %d\n", resultado);
}


    return 0;
}
