.PHONY: pre clean c cs

all: c cs

pre:
	mkdir -p obj bin

clean:
	rm -rf obj bin

c: pre
	gcc c/fib.c -S -o obj/fib.S
	gcc -c obj/fib.S -o obj/fib.o
	gcc obj/fib.o -o bin/fib-c

cs: pre
	mcs -r:System.Numerics -out:bin/fib-cs cs/fib.cs
