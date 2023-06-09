// Código fonte para implementação dos pacotes que serão transportados

#include "../../include/package.h"
#include "../../include/ip.h"

struct package {
    // Identificador do pacote
    int id;
    // Tamanho do pacote (kb) / Peso da aresta
    int size;
    // Endereço de origem
    ip_t *source_ip;
    // Endereço de destino
    ip_t *destination_ip;
};