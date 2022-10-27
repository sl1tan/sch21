// Coryright 2022 chineser

#include <stdio.h>

#define NMAX 10

int input(int *buffer, int *length);
void output(int *buffer, int length);
int sum_numbers(int *buffer, int length);
int find_numbers(int *buffer, int length, int number, int *numbers);

int main() {
    int length, data[NMAX], new_data[NMAX], flag = 1, number;
    if (!input(data, &length)) {
        flag = 0;
    } else {
        if (!sum_numbers(data, length)) {
            printf("n/a");
            flag = 0;
        } else {
            number = sum_numbers(data, length);
            printf("%d\n", number);
            output(new_data, find_numbers(data, length, number, new_data));
        }
    }
    flag++;
    return 0;
}

int input(int *buffer, int *length) {
    int flag = 1;
    if (scanf("%d", length) != 1 || *length > NMAX || *length < 1) {
        printf("n/a");
        flag = 0;
    } else {
        for (int *p = buffer; p - buffer < *length; p++) {
            if (p - buffer + 1 == *length) {
                if (scanf("%d", p) != 1) {
                    printf("n/a");
                    flag = 0;
                    break;
                }
            } else {
                if (scanf("%d", p) != 1 && flag != 0) {
                    printf("n/a");
                    flag = 0;
                    break;
                }
            }
        }
    }
    return flag;
}

void output(int *buffer, int length) {
    for (int i = 0; i < length; i++) {
        printf("%d", buffer[i]);
        if (i != length - 1) {
            printf(" ");
        }
    }
}

int sum_numbers(int *buffer, int length) {
    int sum = 0;
    int count = 0;
    int flag = 1;
    for (int i = 0; i < length; i++) {
        if (buffer[i] % 2 == 0) {
            sum += buffer[i];
            count++;
        }
    }
    if (count == 0) {
        flag = 0;
    } else {
        flag = sum;
    }
    return flag;
}

int find_numbers(int *buffer, int length, int number, int *numbers) {
    int count = 0;
    for (int i = 0; i < length; i++) {
        if (buffer[i] != 0) {
            if (number % buffer[i] == 0) {
                numbers[count] = buffer[i];
                count++;
            }
        }
    }
    if (count == 0) {
        printf("n/a");
    }
    return count;
}
