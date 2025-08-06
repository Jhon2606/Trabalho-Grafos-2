#include <limits.h>        // Para usar a constante INT_MAX (usada como infinito)
#include "dijkstra.h"      // Header onde a função é declarada

// Função que implementa o algoritmo de Dijkstra adaptado para evitar cidades proibidas
int dijkstra(int grafo[MAX][MAX], int n, int origem, int destino, int proibidas[MAX]) {
    int dist[MAX];              // Vetor de distâncias: dist[i] guarda o menor caminho da origem até i
    int pred[MAX];              // Vetor de predecessores (opcional para reconstruir caminho, mas não usado aqui)
    int visitado[MAX] = {0};    // Marca se o vértice i já foi visitado (1) ou não (0)

    // Inicializa todos os vértices com distância infinita e sem predecessores
    for (int i = 1; i <= n; i++) {
        dist[i] = INF;          // INF representa que ainda não há caminho conhecido até i
        pred[i] = -1;           // -1 indica que não há pai conhecido para o vértice i
    }

    // A distância da origem até ela mesma é zero
    dist[origem] = 0;

    // Loop principal do Dijkstra: até visitar todos os vértices
    for (int count = 0; count < n; count++) {
        int cidadeAtual = -1;   // Cidade a ser escolhida na iteração
        int menorDist = INF;    // Inicializa com infinito para comparar distâncias

        // Escolhe o vértice com menor distância que ainda não foi visitado
        for (int i = 1; i <= n; i++) {
            if (!visitado[i] && dist[i] < menorDist) {
                menorDist = dist[i];
                cidadeAtual = i;
            }
        }

        // Se não encontrou nenhuma cidade válida (grafo desconexo ou todas visitadas), encerra o loop
        if (cidadeAtual == -1) break;

        // Marca a cidade atual como visitada
        visitado[cidadeAtual] = 1;

        // Percorre todos os vizinhos da cidade atual
        for (int cidadeVizinha = 1; cidadeVizinha <= n; cidadeVizinha++) {
            // Verifica se há estrada entre cidadeAtual e cidadeVizinha, e se vizinha ainda não foi visitada
            if (grafo[cidadeAtual][cidadeVizinha] != INF && !visitado[cidadeVizinha]) {

                // Se a cidade vizinha for proibida e não for o destino, ignora ela
                if (proibidas[cidadeVizinha] && cidadeVizinha != destino) continue;

                // Se a cidade atual for proibida e não for a origem, ignora também
                if (proibidas[cidadeAtual] && cidadeAtual != origem) continue;

                // Verifica se a distância até a vizinha pode ser melhorada passando por cidadeAtual
                if (dist[cidadeAtual] + grafo[cidadeAtual][cidadeVizinha] < dist[cidadeVizinha]) {
                    dist[cidadeVizinha] = dist[cidadeAtual] + grafo[cidadeAtual][cidadeVizinha]; // Atualiza distância
                    pred[cidadeVizinha] = cidadeAtual;  // Guarda o caminho anterior (não usado diretamente aqui)
                }
            }
        }
    }

    // Retorna a menor distância encontrada até o destino
    // Se não existir caminho válido, o valor será INF
    return dist[destino];
}
