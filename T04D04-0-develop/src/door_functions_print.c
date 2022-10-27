// Copyright 2022 chineser
#include <math.h>
#include <stdio.h>

double Agnesi(double x) {
  double y = 1 / (1 + x * x);
  return y;
}

double Bernoulli(double x) {
  if (sqrt(1 + 4 * x * x) - x * x - 1 < 0)
    return 1;
  double y = sqrt(sqrt(1 + 4 * x * x) - x * x - 1);
  return y;
}

double Hyperbola(double x) {
  double y = 1 / (x * x);
  return y;
}

void printFunc(double func()) {
  char matrix[21][42];
  for (int i = 0; i < 21; i++)
    for (int j = 0; j < 42; j++) {
      matrix[i][j] = ' ';
      if (j == 21)
        matrix[i][j] = 'y';
    }
  for (int i = 0; i < 42; i++)
    matrix[1][i] = 'x';
  double max = -1;
  for (int i = 0; i < 42; i++) {
    double tmp = -M_PI + (2 * M_PI / 41) * i;
    double y = func(tmp);
    if (y > max && y < 5)
      max = y;
  }
  double interval = max / 21;
  for (int i = 0; i < 42; i++) {
    double tmp = -M_PI + (2 * M_PI / 41) * i;
    double y = func(tmp);
    for (int j = 20; j > 0; j--) {
      if (y >= j * interval && y < (j + 1) * interval)
        matrix[j][i] = '*';
    }
  }
  for (int i = 20; i > 0; i--) {
    for (int j = 0; j < 42; j++)
      printf("%c", matrix[i][j]);
    printf("\n");
  }
}

int main() {
  printf("Agnesi\n");
  printFunc(Agnesi);
  printf("\nBernoulli\n");
  printFunc(Bernoulli);
  printf("\nHyperbola\n");
  printFunc(Hyperbola);
  return 0;
}