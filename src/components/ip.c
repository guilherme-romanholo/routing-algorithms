// Código fonte para utilização dos IPs

#include "../../include/ip.h"
#include <stdio.h>
#include <stdlib.h>
#define MASK_1 200
#define MASK_2 145

ip_t *initialize_ip() {
  ip_t *new_ip = malloc(sizeof(ip_t));

  static unsigned int ip_counter = 2;

  new_ip->oct1 = MASK_1;
  new_ip->oct2 = MASK_2;
  new_ip->oct3 = (ip_counter - 2) / 256;
  new_ip->oct4 = (ip_counter - 2) % 256;

  ip_counter++;

  return new_ip;
}

void print_ip(ip_t *ip) {
  printf("%d.%d.%d.%d", ip->oct1, ip->oct2, ip->oct3, ip->oct4);
}

int ip_to_key(ip_t *ip) { return ((ip->oct3 * 255) + ip->oct4 + ip->oct3); }

ip_t *key_to_ip(int key) {
  ip_t *ip = malloc(sizeof(ip_t));

  ip->oct1 = MASK_1;
  ip->oct2 = MASK_2;
  ip->oct3 = key / 256;
  ip->oct4 = key % 256;

  return ip;
}
