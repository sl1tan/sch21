FLAGS = -Wall -Wextra -Werror
CC = gcc
.PHONY: all clean rebuild

all: door_struct stack_test list_test

door_struct: dmanager_module.c
	$(CC) $(FLAGS) -c dmanager_module.c -o dmanager_module.o
	$(CC) $(FLAGS) -o ../build/Quest_1 dmanager_module.o
stack_test: stack stack_tests
	$(CC) $(FLAGS) -o ../build/Quest_3 stack.o stack_test.o
stack: stack.c
	$(CC) $(FLAGS) -c stack.c -o stack.o
stack_tests: stack_test.c
	$(CC) $(FLAGS) -c stack_test.c -o stack_test.o
list_test: list list_tests
	$(CC) $(FLAGS) -o ../build/Quest_2 list.o list_test.o
list: list.c
	$(CC) $(FLAGS) -c list.c -o list.o
list_tests: list_test.c
	$(CC) $(FLAGS) -c list_test.c -o list_test.o
py:
	cp ../materials/linters/CPPLINT.cfg ./CPPLINT.cfg
	python3 ../materials/linters/cpplint.py --extensions=c *.c *.h
clean:
	rm -rf *.o ../build/*
rebuild:
	$(MAKE) clean
	$(MAKE) all