//
// Created by amor e bibi on 11/06/23.
//

#ifndef ROUTINGALGORITHMS_LINK_STATE_H
#define ROUTINGALGORITHMS_LINK_STATE_H

#include "../../include/router.h"
#include "../../include/package.h"
#include<stdio.h>
#include<stdlib.h>

/**
 * Builder do link_state, chamando o algoritmo para cada pacote que o usuário deseja enviar.
 * e imprimindo a matriz de adjacência para mostrar o estado da rede após o envio do pacote.
 * @param origem
 * @param destino
 * @param packages
 * @param num_roteadores
 * @param num_pacotes
 */
void link_state(router_t *origem, router_t *destino, package_t *packages, int num_roteadores, int num_pacotes);

/**
 * Algoritmo que calcula o menor caminho entre a origem e o destino, mostrando o menor caminho
 * e posteriormente atualizando os pesos no grafo.
 * @param origem
 * @param destino
 * @param numero_roteadores
 */
void dijkstra(router_t *origem, router_t *destino, int numero_roteadores, package_t pacote);

/**
 * Imprime a matriz de adjacência que representa a rede.
 * @param matrix
 */
void imprimirMatrizAdjacencia(int **matrix);

#endif //ROUTINGALGORITHMS_LINK_STATE_H
