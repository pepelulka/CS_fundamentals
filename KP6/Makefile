CC=gcc
LD=gcc
CCFLAGS=-Wall -Werror -Wextra -Wfatal-errors -Wpedantic -pedantic-errors -g
LDFLAGS=

src/main: main.o src/abit_dump
	$(LD) $(LDFLAGS) main.o -o src/main
	mkdir build
	mkdir build/bin
	mv *.o build
	mv src/main src/abit_dump build/bin

src/abit_dump: abit_dump.o
	$(LD) $(LDFLAGS) abit_dump.o -o src/abit_dump

abit_dump.o: src/abit_dump.c
	$(CC) $(CCFLAGS) -c src/abit_dump.c -o abit_dump.o

main.o: src/main.c
	$(CC) $(CCFLAGS) -c src/main.c -o main.o

clean:
	rm -r build
