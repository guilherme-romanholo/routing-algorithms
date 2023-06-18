//
// Created by guilherme on 09/06/23.
//

#ifndef ROUTINGALGORITHMS_IP_H
#define ROUTINGALGORITHMS_IP_H




typedef struct ip {
    // Chave para a matriz de adjacencia
    int key;
    // Octetos de um ip, ex: 192.160.0.5
    unsigned int oct1;
    unsigned int oct2;
    unsigned int oct3;
    unsigned int oct4;
}ip_t;

ip_t *initialize_ip(unsigned int mask, unsigned int mask2);
void print_ip(ip_t *ip);
#endif //ROUTINGALGORITHMS_IP_H
