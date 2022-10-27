FLAGS = -Wall -Wextra -Werror
.PHONY: all clean rebuild

all: print_module documentation_module bst_create_test bst_insert_test

print_module: print_modules
	gcc $(FLAGS) -D PRINT -c main_module_entry_point.c -o main_module_entry_point.o
	gcc $(FLAGS) -o ../build/Quest_1 print_module.o main_module_entry_point.o
print_modules: print_module.c
	gcc $(FLAGS) -c print_module.c -o print_module.o
documentation_module: doc_module
	gcc $(FLAGS) -D CHECK -c main_module_entry_point.c -o main_module_entry_point.o
	gcc $(FLAGS) -o ../build/Quest_2 documentation_module.o main_module_entry_point.o
doc_module: documentation_module.c
	gcc $(FLAGS) -c documentation_module.c -o documentation_module.o
bst: bst.c
	gcc $(FLAGS) -c bst.c -o bst.o
bst_create_test: bst
	gcc $(FLAGS) -c bst_create_test.c -o bst_create_test.o
	gcc $(FLAGS) -o ../build/Quest_3 bst_create_test.o bst.o
bst_insert_test: bst
	gcc $(FLAGS) -c bst_insert_test.c -o bst_insert_test.o
	gcc $(FLAGS) -o ../build/Quest_4 bst_insert_test.o bst.o
py:
	cp ../materials/linters/CPPLINT.cfg ./CPPLINT.cfg
	python3 ../materials/linters/cpplint.py --extensions=c *.c *.h
clean:
	rm -rf *.o ../build/*

rebuild:
	$(MAKE) clean
	$(MAKE) all