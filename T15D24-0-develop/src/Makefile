FLAGS = -Wall -Werror -Wextra
.PHONY: all clean rebuild

all: main

main: 
	gcc $(FLAGS)  shared.c modules.c levels.c status_events.c modules_db.c -o Main
clean:
	rm -rf Main temp
py:
	cp ../materials/linters/CPPLINT.cfg ./CPPLINT.cfg
	python3 ../materials/linters/cpplint.py --extensions=c *.c *.h
cp:
	cppcheck --enable=all --suppress=missingIncludeSystem *.c
rebuild:
	$(MAKE) clean
	$(MAKE) all