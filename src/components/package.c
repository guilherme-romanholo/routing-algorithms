// Código fonte para implementação dos pacotes que serão transportados

#include "../../include/package.h"
#include "../../include/ip.h"

#include<stdio.h>
#include<stdlib.h>

package_t *initialize_package(ip_t *source, ip_t *destination, int package_size) {
  package_t *package = malloc(sizeof(package_t));

  package->size = package_size;
  package->source_ip = source;
  package->destination_ip = destination;

  return package;
}
