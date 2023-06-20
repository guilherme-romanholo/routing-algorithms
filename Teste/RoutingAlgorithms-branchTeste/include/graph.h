//
// Created by guilherme on 06/06/23.
//

#ifndef ROUTINGALGORITHMS_GRAPH_H
#define ROUTINGALGORITHMS_GRAPH_H

/**
 * Estrutura do grafo para matriz de adjacencias
 */
typedef struct graph {
  int numNodes;
  int numEdges;
  int **matrix;
} graph_t;

/**
 * Estrutura do grafo em formato de arestas
 */
typedef struct edge {
  int source;
  int destination;
  int weight;
} edge_t;

/**
 * Função para inicializar o grafo com base em um arquivo
 * @return Retorna o grafo
 */
graph_t *initialize_graph(const char *filename);

/**
 * Função para printar o grafo
 * @param graph Grafo para ser printado
 */
void print_graph(graph_t *graph);

/**
 * Função para liberar a memória do grafo
 * @param graph Grafo que será liberado
 */
void free_graph(graph_t *graph);

/**
 * Função para inicializar uma matriz NxN, com as distancias infinitas
 * @param Tamanho da matriz
 * @return Matriz criada
 */
int **initialize_matrix(int n);

/**
 * Função que transforma o grafo em arestas
 * @param graph Grafo para ser transformado
 * @return Vetor de arestas
 */
edge_t *graph_to_edges(graph_t *graph);

#endif // ROUTINGALGORITHMS_GRAPH_H
