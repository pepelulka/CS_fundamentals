CC=gcc
LD=gcc
CCFLAGS=-Wall -Werror -Wextra -Wfatal-errors -Wpedantic -pedantic-errors -g
LDFLAGS=
SOURCES=$(addprefix src/,main.c table.c textmenu.c)
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE=src/main

$(EXECUTABLE): $(OBJECTS)
	$(LD) $(LDFLAGS) $(OBJECTS) -o $(EXECUTABLE)
	mkdir build
	mkdir build/bin
	mv $(EXECUTABLE) build/bin
	mv $(OBJECTS) build

%.o: %.c
	$(CC) $(CCFLAGS) -c $< -o $@

clean:
	rm -r build
