// Código fonte para implementação do algoritmo link state

#include "../../include/link_state.h"


void link_state(int ***matrix, package_t *packages, int routers, int number_packages)
{
    int i;
    for (i = 0; i < number_packages; i++) {
        printMatrix(*matrix, routers);
        dijkstra(matrix, routers, packages[i]);
    }
    printMatrix(*matrix, routers);

}


void dijkstra(int ***matrix, int routers, package_t package)
{
    int cost[routers][routers];
    int count, mindistance;
    int distance[routers];
    int path[routers];
    int previous[routers];
    int visited[routers];
    int last_visited;
    int origin = package.source_ip->key;
    int destination = package.destination_ip->key;
    int i,j, k;

    for(i=0; i < routers; i++)
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
    }

    for (i=0; i < routers; i++)
    {
        distance[i] = *matrix[origin][i];
        visited[i] = 0;
        previous[i] = origin;
    }

    distance[origin] = 0;
    visited[origin] = 1;
    count = 1;

    while(count < routers -1 )
    {
        mindistance = INT_MAX;
        for(i = 0 ; i < routers; i++) {
            if (distance[i] < mindistance && visited[i] == 0) {
                mindistance = distance[i];
                last_visited = i;
            }
        }
            visited[last_visited] = 1;

            for(i=0; i < routers; i++)
            {
                if(visited[i] == 0)
                {
                    if(mindistance + *matrix[last_visited][i] < distance[i])
                    {
                        distance[i] = mindistance + *matrix[last_visited][i];
                        previous[i] = last_visited;
                    }
                }

            }
            count++;
            path[0] = destination;
            j = destination;
            count = 1;
            do
            {
                j = previous[j];
                path[count++] = j;
            }while(j != origin);

            for(i = count -1; i >0; i--)
            {
                j = path[i];
                 k = path[i-1];
                 *matrix[j][k] += package.size;

            }

            print_path(path, count);

    }



}


void printMatrix(int **matrix, int routers) {
    int i, j;
    for (i = 0; i < routers; i++) {
        for (j = 0; j < routers; j++) {
            printf("%d", matrix[i][j]);
        }
        printf("\n");
    }

}

void print_path(int *path, int count)
{
    while(count--)
    {
        printf("%d <- ", path[count]);
    }

}


