// Código fonte para implementação do algoritmo distance vector

#include "../../include/distance_vector.h"
#include "../../include/package.h"
#include <limits.h>
#include <stdio.h>

#define MAX_NODES 1000

void initializeDistances(int distances[], int predecessors[], int numNodes,
                         int sourceNode) {
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

void updateWeight(edge_t edges[], int source, int destination, int numEdges,
                  int packageWeight) {
  // Percorre os nós e vai incrementando o valor das arestas
  for (int i = 0; i < numEdges; i++) {
    if (edges[i].source == source && edges[i].destination == destination) {
      edges[i].weight += packageWeight;
    }
  }
}

void printPath(edge_t edges[], int predecessors[], int destinationNode,
               int numEdges, int packageWeight) {
  // Caso de parada da recursão quando chega no destino
  if (predecessors[destinationNode] == -1) {
    print_ip(key_to_ip(destinationNode));
    printf("(%d) ", destinationNode);
    return;
  }

  // Chamada recursiva com o nó de origem sendo o destino
  printPath(edges, predecessors, predecessors[destinationNode], numEdges,
            packageWeight);

  // Recalcula o peso da aresta percorrida
  updateWeight(edges, predecessors[destinationNode], destinationNode, numEdges,
               packageWeight);

  // Printa o caminho
  print_ip(key_to_ip(destinationNode));
  printf(" (%d) ", destinationNode);
}

void distanceVector(edge_t edges[], int numEdges, int numNodes,
                    package_t *package) {
  // Define os vetor de distância e de predecessores
  int distances[MAX_NODES];
  int predecessors[MAX_NODES];

  // Inicializa as distâncias
  initializeDistances(distances, predecessors, numNodes,
                      ip_to_key(package->source_ip));

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
  printf("Caminho mínimo do nó ");
  print_ip(package->source_ip);
  printf(" (%d) até o nó ", ip_to_key(package->source_ip));
  print_ip(package->destination_ip);
  printf(" (%d).\n", ip_to_key(package->destination_ip));

  // Imprime o caminho do pacote
  printf("Caminho: ");
  printPath(edges, predecessors, ip_to_key(package->destination_ip), numEdges,
            package->size);
  printf("\nDistância: %d\n", distances[ip_to_key(package->destination_ip)]);
}

// Passar os pacotes aqui
void prepareDistanceVector(int num_packages, package_t *package,
                           graph_t *graph) {
  // Exemplo de grafo que será montado a partir do arquivo
  edge_t *edges = graph_to_edges(graph);

  // Número de arestas continua calculando assim
  int numEdges = graph->numEdges;
  // Número de nós obtemos a partir do arquivo
  int numNodes = graph->numNodes;

  for (int i = 0; i < num_packages; i++)
    distanceVector(edges, numEdges, numNodes, package);
}
