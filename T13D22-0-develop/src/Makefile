FLAGS = -Wall -Werror -Wextra
.PHONY: all clean rebuild

all: cipher logging_cipher

cipher: cipher.c
	gcc $(FLAGS) cipher.c logger.c -D LOGS -o ../build/cipher
logging_cipher: cipher.c
	gcc $(FLAGS) cipher.c logger.c -D LOGS -o  ../build/logging_cipher
clean:
	rm -rf *.o ../build/*
py:
	cp ../materials/linters/CPPLINT.cfg ./CPPLINT.cfg
	python3 ../materials/linters/cpplint.py --extensions=c *.c *.h
rebuild:
	$(MAKE) clean
	$(MAKE) all