FLAGS = -Wall -Werror -Wextra
.PHONY: all clean rebuild

all: state_sort state_search clear_state

state_sort: state_sort.c
	gcc $(FLAGS)  state_sort.c binary.c -o ../build/Quest_1
state_search: state_search.c binary.c
	gcc $(FLAGS)  state_search.c binary.c -o ../build/Quest_2
clear_state: state_search.c binary.c
	gcc $(FLAGS)  clear_state.c binary.c -o ../build/Quest_3
clean:
	rm -rf *.o ../build/*
py:
	cp ../materials/linters/CPPLINT.cfg ./CPPLINT.cfg
	python3 ../materials/linters/cpplint.py --extensions=c *.c *.h
rebuild:
	$(MAKE) clean
	$(MAKE) all