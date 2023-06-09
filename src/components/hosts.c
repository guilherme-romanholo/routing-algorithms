// Código fonte para implementação dos hosts que irão trocar os pacotes

#include "../../include/hosts.h"
#include "../../include/ip.h"


struct host {
    char hostname[50];
    ip_t *host_ip;
};