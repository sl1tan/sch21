// Copyright 2022 chineser
#include <math.h>
#include <stdio.h>

void func_anesi();
void func_hyperbola();
void func_bernulli();

int main() {
  double pi = 3.14159265358979323846;
  for (double x = -pi; x <= pi; x += 2 * pi / 41) {
    printf("%.7lf | ", x);
    func_anesi(x);
    func_bernulli(x);
    func_hyperbola(x);
  }

  return 0;
}

void func_anesi(double x) {
  double y = 1 / (1 + x * x);
  if (y != y) {
    printf("- | ");
  } else {
    printf("%.7lf | ", y);
  }
}

void func_bernulli(double x) {
  double y = (double)sqrt(sqrt(1 + 4 * x * x) - x * x - 1);
  if (y != y) {
    printf("- | ");
  } else {
    printf("%.7lf | ", y);
  }
}

void func_hyperbola(double x) {
  double y = 1 / (x * x);
  if (y != y) {
    printf("-\n");
  } else {
    printf("%.7lf\n", y);
  }
}
