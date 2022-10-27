#include "documentation_module.h"
#include <string.h>
#include <stdarg.h>
#include "math.h"
#include <stdio.h>

int validate(char* data) {
    int validation_result = !strcmp(data, Available_document);
    return validation_result;
}

short check_available_documentation_module(int (*validate)(char*), int document_count, ...) {
    va_list factor;
    short check = 0;
    int c = 0;
    va_start(factor, document_count);
    while (document_count) {
        char* doc;
        doc = va_arg(factor, char*);
        if (validate(doc) == 1) {
            check += pow(2, c);
        }
        c++;
        document_count--;
    }
    va_end(factor);
    return check;
}

void output_available_documents(short res, int document_count, ...) {
    va_list factor;
    int p = 1;
    va_start(factor, document_count);
    while (document_count) {
        char* doc;
        doc = va_arg(factor, char*);
        printf("%d. %-15s: ", p, doc);
        if (res % 2 == 0) {
            printf("unavailable\n");
        } else {
            printf("available\n");
        }
        document_count--;
        p++;
        res /= 2;
    }
    va_end(factor);
}
