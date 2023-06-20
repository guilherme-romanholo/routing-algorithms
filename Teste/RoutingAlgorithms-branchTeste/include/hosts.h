//
// Created by guilherme on 06/06/23.
//

#ifndef ROUTINGALGORITHMS_HOSTS_H
#define ROUTINGALGORITHMS_HOSTS_H
#include "ip.h"
typedef struct host {
    char hostname[50];
    ip_t *host_ip;
} host_t;
#endif //ROUTINGALGORITHMS_HOSTS_H
