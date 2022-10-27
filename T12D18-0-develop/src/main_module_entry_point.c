#include <stdio.h>
#include "print_module.h"
#include "documentation_module.h"

int main() {
    #ifdef PRINT
    print_log(print_char, Module_load_success_message);
    #endif
    #ifdef CHECK
    short availability_mask = check_available_documentation_module(validate, Documents_count, Documents);
    output_available_documents(availability_mask, Documents_count, Documents);
    #endif
    return 0;
}

