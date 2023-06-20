//
// Created by guilherme on 06/06/23.
//

#ifndef ROUTINGALGORITHMS_PACKAGE_H
#define ROUTINGALGORITHMS_PACKAGE_H

#include "ip.h"

/**
 * Estrutura de definição do pacote
 */
typedef struct package {
  // Tamanho do pacote (kb) / Peso da aresta
  int size;
  // Endereço de origem
  ip_t *source_ip;
  // Endereço de destino
  ip_t *destination_ip;
} package_t;

/**
 * Função para inicializar um pacote;
 * @param source IP de origem
 * @param destination IP de destino
 * @param package_size Tamanho do pacote
 * @return Pacote criado
 */
package_t *initialize_package(ip_t *source, ip_t *destination,
                              int package_size);

#endif // ROUTINGALGORITHMS_PACKAGE_H
