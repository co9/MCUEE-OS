all:
	gcc main.c core.c mail.c -std=c99 -o main
main: main.c
	gcc main.c core.c -std=c99 -o main
debug:
	gcc main.c core.c -g -Wall -std=c99 -o main
	gdb -q main
