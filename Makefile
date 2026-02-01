CC = gcc
CFLAGS = -Wall -Wextra -O2

SRC = src/main.c src/cli.c
OBJ = $(SRC:.c=.o)
TARGET = hexagon

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(TARGET)

