//
// Created by guilherme on 09/06/23.
//

#ifndef ROUTINGALGORITHMS_IP_H
#define ROUTINGALGORITHMS_IP_H

/**
 * Estrutura do IP
 */
typedef struct ip {
    unsigned int oct1;
    unsigned int oct2;
    unsigned int oct3;
    unsigned int oct4;
}ip_t;

/**
 * Função para inicializar o valor de um IP
 * @return Retorna o IP
 */
ip_t *initialize_ip();

/**
 * Função para printar um ip
 * @param ip IP que vai ser printado
 */
void print_ip(ip_t *ip);

/**
 * Transforma o IP em uma chava para a matriz
 * @param ip IP que será transformado em uma chave
 * @return Retorna a chave
 */
int ip_to_key(ip_t *ip);

/**
 * Transforma uma chave em IP
 * @param key Chave da matriz
 * @return IP obtido pela chave
 */
ip_t *key_to_ip(int key);

#endif //ROUTINGALGORITHMS_IP_H
