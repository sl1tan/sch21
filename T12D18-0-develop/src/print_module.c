#include <stdio.h>
#include <time.h>
#include "print_module.h"

char print_char(char ch)  {
    return putchar(ch);
}

void print_time(char (*print)(char), int n) {
    if (n < 10) {
        print('0');
        print(n + '0');
    } else {
        print(n/10 + '0');
        print(n%10 + '0');
    }
}

void print_log(char (*print)(char), char* message) {
    time_t currT = time(NULL);
    struct tm* aTm = localtime(&currT);
    printf("%s ", Log_prefix);
    print_time(print, aTm->tm_hour);
    printf(":");
    print_time(print, aTm->tm_min);
    printf(":");
    print_time(print, aTm->tm_sec);
    printf(" %s", message);
}
