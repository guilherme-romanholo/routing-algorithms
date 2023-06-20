// Código fonte para implementação do algoritmo link state

#include "../../include/link_state.h"

void link_state(graph_t *G, package_t *packages,  int number_packages)
{
    int i;

    clock_t begin = clock();

    for (i = 0; i < number_packages; i++)
    {
        //printMatrix(G->numNodes, G->matrix);
        printMatrix(G);
        dijkstra(G, packages[i]);
    }
    //printMatrix(G->numNodes, G->matrix);
    
    //return clock();
}

void dijkstra(graph_t *G,  package_t package)
{
    // int cost[routers][routers];
    int count, mindistance;
    int distance[G->numNodes];
    int path[G->numNodes];
    int previous[G->numNodes];
    int visited[G->numNodes];
    int last_visited;
    //int origin = package.source_ip->key;
    //int destination = package.destination_ip->key;
    int origin = ip_to_key(package.source_ip);
    int destination = ip_to_key(package.destination_ip);
    int i, j, k;

    /*for(i=0; i < routers; i++)
    {
        for(j=0;j<routers;j++)
        {
            if(*matrix[i][j] > 0)
            {
                cost[i][j] = *matrix[i][j];
            }
            else
                cost[i][j] = INT_MAX;
        }
    }*/

    for (i = 0; i < G->numNodes; i++)
    {
        if (G->matrix[origin][i] > 0)
        {
            distance[i] = G->matrix[origin][i];
        }
        else
        {
            distance[i] = INT_MAX;
        }
        visited[i] = 0;
        previous[i] = origin;
    }

    distance[origin] = 0;
    visited[origin] = 1;
    count = 1;

    while (count < G->numNodes - 1)
    {
        mindistance = INT_MAX;
        for (i = 0; i < G->numNodes; i++)
        {
            if (distance[i] < mindistance && visited[i] == 0)
            {
                mindistance = distance[i];
                last_visited = i;
            }
        }
        visited[last_visited] = 1;

        for (i = 0; i < G->numNodes; i++)
        {
            if (visited[i] == 0)
            {
                if (G->matrix[last_visited][i] > 0 && mindistance + G->matrix[last_visited][i] < distance[i])
                {
                    distance[i] = mindistance + G->matrix[last_visited][i];
                    previous[i] = last_visited;
                }
            }
        }
        count++;
    }

    path[0] = j = destination;
    count = 1;
    do
    {
        j = previous[j];
        path[count++] = j;
    } while (j != origin);

    for (i = count - 1; i > 0; i--)
    {
        j = path[i];
        k = path[i - 1];
        G->matrix[j][k] += package.size;
    }

    print_path(path, count);
}

//void printMatrix(int routers, int matrix[][routers])
//{
//    int i, j;
//    for (i = 0; i < routers; i++)
//    {
//        for (j = 0; j < routers; j++)
//        {
//            printf("%d ", matrix[i][j]);
//        }
//        printf("\n");
//    }
//    printf("\n");
//    printf("\n");
//}

void printMatrix(graph_t *G){
    int i, j;
    for (i = 0; i < G->numNodes; i++)
    {
        for (j = 0; j < G->numNodes; j++)
        {
            printf("%d ", G->matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    printf("\n");
}

void print_path(int *path, int count)
{
    while (count--)
    {
        printf("%d", path[count]);
        if(count)
            printf("->");
    }
    printf("\n");
}
