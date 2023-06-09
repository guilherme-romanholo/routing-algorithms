//
// Created by guilherme on 09/06/23.
//

#ifndef ROUTINGALGORITHMS_IP_H
#define ROUTINGALGORITHMS_IP_H

typedef struct ip ip_t;

ip_t *initialize_ip(unsigned int mask, unsigned int mask2);
void print_ip(ip_t *ip);

#endif //ROUTINGALGORITHMS_IP_H
