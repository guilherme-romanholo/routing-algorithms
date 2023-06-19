// Código fonte para implementação do algoritmo distance vector

#include <limits.h>
#include <stdio.h>
#include "../../include/distance_vector.h"

#define MAX_NODES 100

void initializeDistances(int distances[], int predecessors[], int numNodes, int sourceNode) {
    // Laço para iniciar as arestas
    for (int i = 0; i < numNodes; i++) {
        // Caso for o vértice de origem inicializa com zero, se não com infinito
        if (i == sourceNode) {
            distances[i] = 0;
        } else {
            distances[i] = INT_MAX;
        }
        // Incializa sem predecessores
        predecessors[i] = -1;
    }
}

void printRoutingTable(int distances[], int predecessors[], int numNodes) {
    printf("Tabela de Roteamento:\n");
    printf("Destino\t\tPróximo Salto\tDistância\n");
    for (int i = 0; i < numNodes; i++) {
        printf("%d\t\t", i);
        // Verifica se tem predecessor para printar
        if (predecessors[i] != -1) {
            printf("%d\t\t", predecessors[i]);
        } else {
            printf("-\t\t");
        }
        // Verificar se possui alguma distancia não infinita
        if (distances[i] != INT_MAX) {
            printf("%d", distances[i]);
        } else {
            printf("-");
        }
        printf("\n");
    }
    printf("\n");
}

void updateWeight(struct Edge edges[], int source, int destination, int numEdges, int packageWeight) {
    // Percorre os nós e vai incrementando o valor das arestas
    for (int i = 0; i < numEdges; i++) {
        if (edges[i].source == source && edges[i].destination == destination) {
            edges[i].weight += packageWeight;
        }
    }
}

void printPath(struct Edge edges[], int predecessors[], int destinationNode, int numEdges, int packageWeight) {
    // Caso de parada da recursão quando chega no destino
    if (predecessors[destinationNode] == -1) {
        printf("%d ", destinationNode);
        return;
    }

    // Chamada recursiva com o nó de origem sendo o destino
    printPath(edges, predecessors, predecessors[destinationNode], numEdges, packageWeight);

    // Recalcula o peso da aresta percorrida
    updateWeight(edges, predecessors[destinationNode], destinationNode, numEdges, packageWeight);

    // Printa o caminho
    printf("%d ", destinationNode);
}

void distanceVector(struct Edge edges[], int numEdges, int numNodes, int sourceNode, int destinationNode) {
    // Define os vetor de distância e de predecessores
    int distances[MAX_NODES];
    int predecessors[MAX_NODES];

    // Inicializa as distâncias
    initializeDistances(distances, predecessors, numNodes, sourceNode);

    // Executa o algoritmo de Bellman-Ford
    for (int i = 0; i < numNodes - 1; i++) {
        for (int j = 0; j < numEdges; j++) {
            int u = edges[j].source;
            int v = edges[j].destination;
            int weight = edges[j].weight;

            if (distances[u] != INT_MAX && distances[u] + weight < distances[v]) {
                distances[v] = distances[u] + weight;
                predecessors[v] = u;
            }
        }
        // Imprime a tabela de roteamento
        printf("Hop %d:\n", i + 1);
        printRoutingTable(distances, predecessors, numNodes);
    }

    // Verifica se há ciclos de peso negativo
    for (int i = 0; i < numEdges; i++) {
        int u = edges[i].source;
        int v = edges[i].destination;
        int weight = edges[i].weight;

        if (distances[u] != INT_MAX && distances[u] + weight < distances[v]) {
            printf("Ciclo de peso negativo detectado!\n");
            return;
        }
    }

    // Imprime o caminho mínimo e os "hops" até o nó de destino
    printf("Caminho mínimo do nó %d ao nó %d:\n", sourceNode, destinationNode);
    printf("Caminho: ");
    printPath(edges, predecessors, destinationNode, numEdges, 5);
    printf("\nDistância: %d\n", distances[destinationNode]);
}

// Passar os pacotes aqui
void prepareDistanceVector(int sourceNode, int destinationNode /*, Grafo de roteadores, pode ser até uma matriz*/) {
    // Exemplo de grafo que será montado a partir do arquivo
    struct Edge edges[] = {{0, 1, 1},
                           {0, 2, 2},
                           {1, 3, 1},
                           {1, 4, 5},
                           {2, 4, 7},
                           {3, 4, 8},
                           {3, 5, 1},
                           {5, 4, 1}};
    // Número de arestas continua calculando assim
    int numEdges = sizeof(edges) / sizeof(edges[0]);
    // Número de nós obtemos a partir do arquivo
    int numNodes = 6;

    distanceVector(edges, numEdges, numNodes, sourceNode, destinationNode);
    //Chamo a função para recalcular o caminho mínimo após aumentar os pesos com o peso do pacote
    // distanceVector(edges, numEdges, numNodes, sourceNode, destinationNode);
}