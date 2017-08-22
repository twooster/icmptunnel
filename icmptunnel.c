/**
 * icmp_tunnel.c
 */

#include "tunnel.h"

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define ARG_SERVER_MODE "-s"
#define ARG_CLIENT_MODE "-c"

void usage()
{
  printf("Wrong argument\n");
  printf("usage: icmptunnel <-s serverip | -c clientip> [tun0]\n");
}

int main(int argc, char *argv[])
{
  char ip_addr[100] = {0,};
  char device[32] = "tun0";

  if (argc < 3) {
    usage();
    exit(EXIT_FAILURE);
  }

  if (strlen(argv[2]) >= sizeof(ip_addr)) {
    usage();
    exit(EXIT_FAILURE);
  }
  strncpy(ip_addr, argv[2], sizeof(ip_addr));

  if (argc > 3) {
    if (strlen(argv[3]) >= sizeof(device)) {
      usage();
      exit(EXIT_FAILURE);
    }
    strncpy(device, argv[3], sizeof(device));
  }

  if (strcmp(argv[1], ARG_SERVER_MODE) == 0) {
    run_tunnel(device, ip_addr, 1);
  }
  else if (strcmp(argv[1], ARG_CLIENT_MODE) == 0) {
    run_tunnel(device, ip_addr, 0);
  }
  else {
    usage();
    exit(EXIT_FAILURE);
  }

  return EXIT_SUCCESS;
}
