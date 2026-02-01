CC=gcc
CFLAGS=-Wall -Wextra -O2
TARGET=hexagon

SRC=src/main.c src/cli.c

all:
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET)

clean:
	rm -f $(TARGET)
