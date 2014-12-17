.PHONY: c

c:
	mkdir -p obj bin
	gcc c/fib.c -S -o obj/fib.S
	gcc -c obj/fib.S -o obj/fib.o
	gcc obj/fib.o -o bin/fib
