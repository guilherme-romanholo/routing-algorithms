//
// Created by guilherme on 06/06/23.
//

#ifndef ROUTINGALGORITHMS_DISTANCE_VECTOR_H
#define ROUTINGALGORITHMS_DISTANCE_VECTOR_H

/**
 * Estrurura referente as arestas do grafo
 */
struct Edge {
    int source;
    int destination;
    int weight;
};

/**
 * Função para incializar as arestas do grafo
 * @param distances Vetor de distâncias
 * @param predecessors Vetor dos predecessores
 * @param numNodes Número de vértices
 * @param sourceNode Vértice de origem
 */
void initializeDistances(int distances[], int predecessors[], int numNodes, int sourceNode);

/**
 * Função para imprimir a tabela de roteamento
 * @param distances Vetor de distâncias
 * @param predecessors Vetor de predecessores
 * @param numNodes Número de vértices
 */
void printRoutingTable(int distances[], int predecessors[], int numNodes);

/**
 * Função para atualizar o peso das arestas conforme o pacote percorre o grafo
 * @param edges Vetor das arestas
 * @param source Posição de origem do pacote
 * @param destination Posiçaõ de destino do pacote
 * @param numEdges Número de arestas
 * @param packageWeight Peso do pacote
 */
void updateWeight(struct Edge edges[], int source, int destination, int numEdges, int packageWeight);

/**
 * Função para printar o caminho que o pacote faz da origem até o destino
 * @param edges Vetor de arestas
 * @param predecessors Vetor de predecessores
 * @param destinationNode Nó de destino
 * @param numEdges Número de arestas
 * @param packageWeight Peso do pacote
 */
void printPath(struct Edge edges[], int predecessors[], int destinationNode, int numEdges, int packageWeight);

/**
 * Função principal para calcular o caminho mínimo pelo algoritimo distance vector
 * @param edges Vetor de arestas
 * @param numEdges Número de arestas
 * @param numNodes Número de nós
 * @param sourceNode Nó de origem
 * @param destinationNode Nó de destino
 */
void distanceVector(struct Edge edges[], int numEdges, int numNodes, int sourceNode, int destinationNode);

#endif //ROUTINGALGORITHMS_DISTANCE_VECTOR_H
