CC=gcc
CFLAGS=-Wall
DEBUG=-g
REL=-s

ANSI=-ansi

SRCMODULES=field.c snake.c
OBJMODULES=$(SRCMODULES:.c=.o)
HEDMODULES=$(SRCMODULES:.c=.h)

%.o: %.c %.h
	$(CC) $(CFLAGS) $(DEBUG) $< -c -o $@

main: main.c $(OBJMODULES)
	$(CC) $(CFLAGS) $(DEBUG) $^ -o $@