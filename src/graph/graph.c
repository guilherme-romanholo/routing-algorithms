//// Código fonte para implementação do grafo
//
//#include "../../include/graph.h"
//#include <stdio.h>
//#include <stdlib.h>
//
//// Cria um nó do grafo
//Package criaPackage (int id, char *commit, int tempo, int IPDestino, int peso) {
//	Package n = (Package) malloc(sizeof(struct package));
//
//    n->id = id;
//	strcpy(n->commit, commit);
//    n-> tempo;
//    n-> IPDestino;
//    n-> peso;
//    n->prox = NULL;
//
//    return n;
//}
//
//// Adiciona um nó Package grafo
//void addPackage (Package n, int id, char *commit, int tempo, int IPDestino, int peso) {
//	Package aux = criaPackage(id, commit, tempo, IPDestino, peso);
//	if(n == NULL)
//		return;
//
//	while(n->prox != NULL)
//		n = n->prox;
//
//	n->prox = aux;
//}
//
//// Imprime a lista de todos os nós adjacentes ao nó corrente n
//void imprimePackage(Package n){
//	while(n != NULL){
//		printf("-> (ID: %d, Commit: %s, Tempo: %d, IP Destino: %d, Peso: %d)", n->id, n->commit, n-> tempo, n->IPDestino, n->peso);
//		n = n->prox;
//    }
//}
//
//// Define uma maquina vazia
//Maquina criaMaquina(char *tipo){
//	Maquina G = (Maquina) malloc(sizeof(struct maquina));
//
//	G->nPackage = 0;
//    G->IP = IPAtual++;
//	strcpy(G->tipo, tipo);
//    G->vertices = NULL;
//    G->contido = NULL;
//
//	return G;
//}
//
//// Efetuar a leitura do grafo via arquivo e retorna a matriz adjacente
//int **readMaquina(char *nomeArq) {
//  /* Pegar um codigo melhor, o meu esta uma carniça
//
//  FILE *fp;
//  char buffer[tam_fila];
//  int **aux;
//  int nPackage, i, j, o, d, val;
//  fp = fopen(nomeArq, "r");
//
//  fgets(buffer, tam_fila, fp);
//  sscanf(buffer, "%d", &nPackage);
//
//  // Inicializa matriz adjacencia
//  aux = (int **)malloc(nPackage * sizeof(int *));
//  for (i = 0; i < maxIPs; i++) {
//    aux[i] = (int *)malloc(maxIPs * sizeof(int));
//    for (j = 0; j < maxIPs; j++)
//      aux[i][j] = 0;
//
//  }
//
//  // Leitura dos arquivos de texto
//  while (!feof(fp)) {
//    fgets(buffer, tam_fila, fp);
//    sscanf(buffer, "%d %d %d", &o, &d, &val);
//    aux[o][d] = val;
//  }
//
//  fclose(fp);
//
//  return aux;*/
//}
//
////Imprime o grafo a partir das listas de adjacencia
//void printMaquina(Maquina G) {
//	int i;
//	printf("\nGrafo - Lista de Adjacencia\n\n");
//	for(i = 0; i < G->nPackage; i++){
//		printf("(%d)", (G->vertices + i)->id);
//		imprimePackage((G->vertices + i));
//		printf("\n");
//	}
//}