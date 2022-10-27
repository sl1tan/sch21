// Copyright 2022 chineser
#include <stdio.h>

long int fibonaci(int a);

int main() {
  int x;
  char c;
  if (scanf("%d", &x) == 1 && (x >= 0)) {
    scanf("%c", &c);
    if (c == '\n' || c == '\0' || c == ' ') {
      printf("%ld", fibonaci(x));
    } else {
      printf("n/a");
    }
    return 0;
  } else {
    printf("n/a");
  }
}

long int fibonaci(int a) {
  if (a == 0)
    return 0;
  if ((a == 1) || (a == 2))
    return 1;
  return fibonaci(a - 1) + fibonaci(a - 2);
}
