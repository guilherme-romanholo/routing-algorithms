//
// Created by amor e bibi on 11/06/23.
//

#ifndef ROUTINGALGORITHMS_LINK_STATE_H
#define ROUTINGALGORITHMS_LINK_STATE_H

#include "../../include/router.h"
#include "../../include/package.h"
#include "../../include/ip.h"
#include<stdio.h>
#include<stdlib.h>
#include <limits.h>

/**
 * Builder do link_state, chamando o algoritmo para cada pacote que o usuário deseja enviar.
 * e imprimindo a matriz de adjacência para mostrar o estado da rede após o envio do pacote.
 * @param origin
 * @param destination
 * @param packages
 * @param routers
 * @param number_packages
 */
void link_state(int ***matrix, package_t *packages, int routers, int number_packages);

/**
 * Algoritmo que calcula o menor caminho entre a origem e o destino, mostrando o menor caminho
 * e posteriormente atualizando os pesos no grafo.
 * @param origin
 * @param destination
 * @param routers
 */
void dijkstra(int ***matrix, int routers, package_t package);

/**
 * Imprime a matriz de adjacência que representa a rede.
 * @param matrix
 */
void printMatrix(int **matrix, int routers);

/**
 * Imprime o caminho encontrado no djikistra
 * @param path
 * @param count
 */
void print_path(int *path, int count);
#endif //ROUTINGALGORITHMS_LINK_STATE_H
