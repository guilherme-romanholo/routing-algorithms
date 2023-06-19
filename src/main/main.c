#include <stdio.h>
#include "../../include/link_state.h"

int main() {
    printf("TUBARAO TE AMO \n");

    int matriz[4][4] = {
        {0, 1, 3, 0},
        {0, 0, 1, 0},
        {0, 0, 0, 0},
        {2, 0, 0, 0}
    };

    package_t packages[2];
    ip_t source, dest;

    source.key = 0;
    dest.key = 2;

    packages[0].source_ip = &source;
    packages[0].destination_ip = &dest;
    packages[0].size = 1;

    packages[1].source_ip = &source;
    packages[1].destination_ip = &dest;
    packages[1].size = 1;

    link_state( 4, matriz, packages,  2);

    return 0;
}
