// Copyright 2022 chineser
#include <stdio.h>

void code();
void decode();

int main(int argc, char *argv[]) {
  if (argc == 2) {
    if (*argv[1] == '0') {
      code();
    } else if (*argv[1] == '1') {
      decode();
    } else {
      printf("n/a");
      }
  } else {
    printf("n/a");
    }
  return 0;
}

void code() {
  int amount;
  char arg, space;
  while ((amount = scanf("%c%c", &arg, &space)) && amount == 2 &&
         space == ' ') {
    printf("%X ", arg);
  }
  if (amount != -1 && (space < 32 || space > 126)) {
    printf("%X", arg);
  } else {
    printf("n/a");
    }
}

void decode() {
  int amount = 0, key;
  char space;
  while ((amount = scanf("%X%c", &key, &space)) && amount == 2 &&
         space == ' ') {
    printf("%c ", (char)key);
  }
  if (amount != -1 && (key > 32 && key < 126)) {
    printf("%c", (char)key);
  } else {
    printf("n/a");
    }
}
