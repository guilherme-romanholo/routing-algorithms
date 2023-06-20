#include <stdio.h>
#include <time.h>
#include "../../include/link_state.h"
#include "../../include/graph.h"
#include "../../include/distance_vector.h"
#define package_size 5

double prepareDistanceVector (graph_t *G, package_t *packages, int nPackages) {    
  // Exemplo de grafo que será montado a partir do arquivo
  edge_t *edges = graph_to_edges(G);

  clock_t begin = clock();

  for (int i = 0; i < nPackages; i++)
    distanceVector (edges, G->numEdges, G->numNodes, packages);

  clock_t end = clock();

  free_graph(G);
  free(packages);

  return (end - begin) / CLOCKS_PER_SEC;
}

double prepareLinkState(graph_t *G, package_t *packages, int nPackages){
  //package_t packages[nPackages];
  //int matriz[4][4] = {
  //      {0, 1, 3, 0},
  //      {0, 0, 1, 0},
  //      {0, 0, 0, 0},
  //      {2, 0, 0, 0}
  //  };

  //for (int i = 0;  i < nPackages; i++){
  //  packages[i].source_ip = source;
  //  packages[i].destination_ip = dest;
  //  packages[i].size = package_size;
  //}

  clock_t begin = clock();
  link_state (G, packages,  nPackages);

  return (double)(clock() - begin) / CLOCKS_PER_SEC;
}

void selectHost(graph_t *G, int nPackages){
  // Mensagem inicial
  int oct4;
  printf("Escolha o IP para quem deseja enviar a mensagem (apenas o final).\n");
  scanf("%d", &oct4); // Se numero > 256, automaticamente troca a rede

  // Inicializacao dos Packages
  package_t *packages = malloc (nPackages * sizeof(package_t));
  ip_t *source, *dest;

  source = key_to_ip(0);
  dest = key_to_ip(oct4);

  for (int i = 0; i < nPackages; i++)
    packages = initialize_package(source, dest, package_size);

  // Matriz estatica pro link state

  // Contar tempo total execução
  clock_t begin = clock();
  double timeLinkState = prepareLinkState(G, packages, nPackages);
  //double timeDistanceVector = prepareDistanceVector(G, packages, nPackages);

  // Imprime as diferenças
  printf("Tempo de execucao Link State(ms): %.2f\n", timeLinkState * 1000);
  //printf("Tempo execucao Distance Vector(ms): %.2f\n", timeDistanceVector * 1000);
  printf("Tempo total de execucao(ms): %.2f\n", (double)((clock()-begin) * 1000) / CLOCKS_PER_SEC);  
}

int main() {
    printf("===== Seja Bem-Vindo =====\n");
    int opt;

    graph_t *G = initialize_graph("/home/willao/Documentos/GitHub/RoutingAlgorithms/src/graph/graph_1.txt");

    do {
        
        printf("======== OPERACOES ========\n");
        printf("1. Enviar mensagem\n"); // Computer <-> Server
        printf("2. Acessar site\n"); // Computer <-> Server
        printf("3. Voltar\n");
        printf("==========================\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opt);

        switch (opt) {
            case 1:
                printf("Você escolheu a opcao Enviar Mensagem.\n");
                selectHost(G, 5);
                break;
            case 2:
                printf("Você escolheu a opcao Acessar Site.\n");
                selectHost(G, 20);
                break;
            case 3:
                return 0;   
            default:
                printf("Opcao invalida! Tente novamente.\n");
                break;
        }

        printf("\n");
    } while (opt != 3);

    return 0;
}

