FLAGS = -Wall -Werror -Wextra
CC = gcc
.PHONY: all clean rebuild

all: strlen_tests strcmp_tests strcpy_tests strcat_tests strchr_tests strstr_tests strtok_tests
strlen_tests: s21_string s21_string_test
	$(CC) -c $(FLAGS) -DSTRLEN main.c -o main.o
	$(CC) $(FLAGS) -o ../build/Quest_1 s21_string.o s21_string_test.o main.o
strcmp_tests: s21_string s21_string_test
	$(CC) -c $(FLAGS) -DSTRCMP main.c -o main.o
	$(CC) $(FLAGS) -o ../build/Quest_2 s21_string.o s21_string_test.o main.o
strcpy_tests: s21_string s21_string_test
	$(CC) -c $(FLAGS) -DSTRCPY main.c -o main.o
	$(CC) $(FLAGS) -o ../build/Quest_3 s21_string.o s21_string_test.o main.o
strcat_tests: s21_string s21_string_test
	$(CC) -c $(FLAGS) -DSTRCAT main.c -o main.o
	$(CC) $(FLAGS) -o ../build/Quest_4 s21_string.o s21_string_test.o main.o
strchr_tests: s21_string s21_string_test
	$(CC) -c $(FLAGS) -DSTRCHR main.c -o main.o
	$(CC) $(FLAGS) -o ../build/Quest_5 s21_string.o s21_string_test.o main.o
strstr_tests: s21_string s21_string_test
	$(CC) -c $(FLAGS) -DSTRSTR main.c -o main.o
	$(CC) $(FLAGS) -o ../build/Quest_6 s21_string.o s21_string_test.o main.o
strtok_tests: s21_string s21_string_test
	$(CC) -c $(FLAGS) -DSTRTOK main.c -o main.o
	$(CC) $(FLAGS) -o ../build/Quest_7 s21_string.o s21_string_test.o main.o
text_processor: s21_string.o processor.o
	$(CC) $(FLAGS) s21_string.o processor.o -o ../build/Quest_8
processor.o: text_processor.c
	$(CC) -c text_processor.c -o processor.o
s21_string:	s21_string_test.c
	$(CC) $(FLAGS) -c s21_string.c -o s21_string.o
s21_string_test: s21_string.c
	$(CC) $(FLAGS) -c s21_string_test.c -o s21_string_test.o
clean:
	rm -rf *.o ../build/*
rebuild:
	$(MAKE) clean
	$(MAKE) all