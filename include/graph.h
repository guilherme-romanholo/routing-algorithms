//
// Created by guilherme on 06/06/23.
//

#ifndef ROUTINGALGORITHMS_GRAPH_H
#define ROUTINGALGORITHMS_GRAPH_H
#define tam_fila 100
#define maxIPs 10

#endif //ROUTINGALGORITHMS_GRAPH_H

//EDs para nó e grafo
//----------------------------------


/**
 * Tipos:
 * PC
 * Router
 * Server
*/
struct maquina {
    int IP; // IP da maquina
    int nPackage; // Numero de packages que conecta
	char tipo[6]; // Tipo da maquina
	Package vertices; // Conexoes
    Package contido; // Contido na maquina atual, apenas 1 por vez 
};

typedef struct maquina *Maquina;

static int IPAtual = "192 168 0 00";
//----------------------------------

//Implementação das funções/operações
//----------------------------------
Package criaPackage (int id, char *commit, int tempo, int IPDestino, int peso);
void addPackage (Package n, int id, char *commit, int tempo, int IPDestino, int peso);
void imprimePackage(Package n);
Maquina criaMaquina(char *tipo);
int **readMaquina(char *nomeArq);
void printMaquina(Maquina G);
//----------------------------------