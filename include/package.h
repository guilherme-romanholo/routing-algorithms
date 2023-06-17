//
// Created by guilherme on 06/06/23.
//

#ifndef ROUTINGALGORITHMS_PACKAGE_H
#define ROUTINGALGORITHMS_PACKAGE_H

#include "ip.h"
typedef struct package {
    // Identificador do pacote
    int id;
    // Tamanho do pacote (kb) / Peso da aresta
    int size;
    // Endereço de origem
    ip_t *source_ip;
    // Endereço de destino
    ip_t *destination_ip;
}package_t;
#endif //ROUTINGALGORITHMS_PACKAGE_H
