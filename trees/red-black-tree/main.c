#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
  char *hello = argv[1];
  char *world = argv[2];

  printf("%s %s", hello, world);

  return 0;
}
