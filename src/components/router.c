// Código fonte para implementação dos roteadores

#include "../../include/router.h"
#include "../../include/ip.h"

struct router {
    // Como id usuaremos a key definida no ip
    ip_t *ip;

    // ------- Distance Vector (Bellman-Ford) -------
    // Número de roteadores vizinhos
    unsigned int num_neighbors;
    // Array com as keys dos vizinhos
    unsigned int neighbors[MAX_ROUTERS];
    // Array com os custos dos vizinhos
    unsigned int neighbors_costs[MAX_ROUTERS];

    // -------- Link State (Dijkstra) -------
    // Referencia para matriz de adjacencia compartilhada por todos
    unsigned int (*adjacencyMatrix)[MAX_ROUTERS];
};
