// Código fonte para implementação do grafo
#include "../../include/graph.h"
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

graph_t *initialize_graph(const char *filename) {
  FILE *fp = fopen(filename, "r");
  int source, destination, weight;
  graph_t *graph = malloc(sizeof(graph_t));

  fscanf(fp, "%d", &(graph->numNodes));

graph->matrix = initialize_matrix(graph->numNodes);
  graph->numEdges = 0;

  while (fscanf(fp, "%d %d %d", &source, &destination, &weight) != EOF){
    graph->matrix[source][destination] = weight;
    graph->numEdges++;
  }

  fclose(fp);

  return graph;
}

void print_graph(graph_t *graph) {
  for (int i = 0; i < graph->numNodes; i++) {
    for (int j = 0; j < graph->numNodes; j++) {
      if (graph->matrix[i][j] == INT_MAX)
        printf("- ");
      else
        printf("%d ", graph->matrix[i][j]);
    }
    printf("\n");
  }
}

void free_graph(graph_t *graph) {
  for (int i = 0; i < graph->numNodes; i++) {
    free(graph->matrix[i]);
  }
  free(graph->matrix);
  free(graph);
}

int **initialize_matrix(int n) {
  int **matrix = malloc(sizeof(int *) * n);

  for (int i = 0; i < n; i++)
    matrix[i] = malloc(sizeof(int) * n);

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (i == j)
        matrix[i][j] = 0;
      else
        matrix[i][j] = INT_MAX;
    }
  }

  return matrix;
}

edge_t *graph_to_edges(graph_t *graph) {
  edge_t *edges = malloc(sizeof(edge_t) * graph->numEdges);
  int n = 0;

  for (int i = 0; i < graph->numNodes; i++) {
    for (int j = 0; j < graph->numNodes; j++) {
      if(graph->matrix[i][j] != 0 && graph->matrix[i][j] != INT_MAX) {
        edges[n].source = i;
        edges[n].destination = j;
        edges[n].weight = graph->matrix[i][j];
        n++;
      }
    }
  }

  return edges;
}
