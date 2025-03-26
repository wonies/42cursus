#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
  char pie[] = "3.1415";
  char *pEnd;
  double d1, d2;
  if (argc != 2) {
    printf("Usage : %s [radius]\n", argv[0]);
    return 1;
  }
  d1 = strtod(pie, &pEnd);
  d2 = strtod(argv[1], &pEnd);
  printf("PIE : %f\n", d1);
  printf("반지름 : %f\n", d2);
  printf("원의 둘레 : %f\n", d1 * d2 * 2.0);
  return 0;
}