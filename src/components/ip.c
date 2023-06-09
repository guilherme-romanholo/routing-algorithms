//
// Created by guilherme on 09/06/23.
//

#include "../../include/ip.h"
#include <stdlib.h>
#include <stdio.h>

struct ip {
    // Chave para a matriz de adjacencia
    int key;
    // Octetos de um ip, ex: 192.160.0.5
    unsigned int oct1;
    unsigned int oct2;
    unsigned int oct3;
    unsigned int oct4;
};

// Considerando uma rede com máscara /16, ou seja, passamos a máscara da rede
// por exemplo: 192.168.0.0 , assim ele realizará automáticamente o endereçamento
// dos hosts dessa rede, por exemplo 192.168.0.1, 192.168.0.2, ..., 192.168.255.255
// Nesse caso terão 65536 hosts disponíveis
ip_t *initialize_ip(unsigned int mask, unsigned int mask2) {
    ip_t *new_ip = malloc(sizeof(ip_t));

    static unsigned int ip_counter = 2;

    new_ip->oct1 = mask;
    new_ip->oct2 = mask2;
    new_ip->oct3 = (ip_counter - 1) / 256;
    new_ip->oct4 = (ip_counter - 1) % 256;
    new_ip->key = new_ip->oct3 + new_ip->oct4;

    ip_counter++;

    return new_ip;
}

void print_ip(ip_t *ip) {
    printf("%d.%d.%d.%d\n",ip->oct1,ip->oct2,ip->oct3,ip->oct4);
}