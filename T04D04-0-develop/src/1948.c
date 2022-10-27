// Copyright 2022 chineser
#include <math.h>
#include <stdio.h>

int check_on_div(int n, int a);
int simple(int a);
int Nod(int x);

int main() {
  int inp;
  char c;

  if (scanf("%d", &inp) == 1 && (inp != 0) && (inp != 1) && (inp != -1)) {
    scanf("%c", &c);
    if (c == '\n' || c == '\0' || c == ' ') {
      if (inp < 0) {
        inp = -inp;
      }
      printf("%d", Nod(inp));
    } else {
      printf("n/a");
    }

  } else {
    printf("n/a");
  }

  return 0;
}

int check_on_div(int n, int a) {
  int current = n;
  while (current >= 0) {
    current -= a;
  }
  if (current + a == 0)
    return 1;
  else
    return 0;
}

int simple(int a) {
  for (int i = 2; i <= sqrt(a); i++) {
    if (check_on_div(a, i))
      return 0;
  }
  return 1;
}

int Nod(int x) {
  int div_max = 1, i;
  for (i = 2; i <= x; i++) {
    if (check_on_div(x, i) && simple(i)) {
      div_max = i;
    }
  }
  return div_max;
}
