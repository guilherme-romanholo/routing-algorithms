// Código fonte para implementação do algoritmo link state

#include "../../include/link_state.h"

void link_state(router_t *origem, router_t *destino, package_t *packages, int num_roteadores, int num_pacotes) {
    int i;
    for (i = 0; i < num_pacotes; i++) {
        imprimirMatrizAdjacencia(origem->adjacencyMatrix);
        dijkstra(origem, destino, num_roteadores, packages[i]);
    }
    imprimirMatrizAdjacencia(origem->adjacencyMatrix);

}


void dijkstra(router_t *origem, router_t *destino, int numero_roteadores, package_t pacote)
{


}


void imprimirMatrizAdjacencia(int **matrix) {
    int i, j;
    for (i = 0; i < MAX_ROUTERS; i++) {
        for (j = 0; j < MAX_ROUTERS; j++) {
            printf("%d", matrix[i][j]);
        }
        printf("\n");
    }

}

