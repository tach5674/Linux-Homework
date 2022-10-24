compile_str:
	@gcc  str.c -c -Werror -Wall
compile_main:
	@gcc main.c -c -Werror -Wall
link:
	@gcc str.o main.o -o task2 -Werror -Wall -g -fsanitize=address,undefined

run: compile_str compile_main link
	@./task2 123 abc abc123
