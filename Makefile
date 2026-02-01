# =====================
# HEXAGON Makefile
# v0.0.3-alpha
# =====================

CC      = gcc
CFLAGS  = -Wall -Wextra -std=c11 -g
TARGET  = hexagon

SRC_DIR = src
OBJ_DIR = build

SRCS = \
	$(SRC_DIR)/main.c \
	$(SRC_DIR)/cli/cli.c \
	$(SRC_DIR)/core/hexagon.c \
	$(SRC_DIR)/modules/honeypot.c \
	$(SRC_DIR)/utils/log.c

OBJS = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

# =====================
# DEFAULT TARGET
# =====================
all: $(TARGET)

# =====================
# LINK
# =====================
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS)

# =====================
# COMPILE
# =====================
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

# =====================
# INSTALL / UNINSTALL
# =====================
install: $(TARGET)
	sudo install -m 755 $(TARGET) /usr/local/bin/$(TARGET)

uninstall:
	sudo rm -f /usr/local/bin/$(TARGET)

# =====================
# CLEAN
# =====================
clean:
	rm -rf $(OBJ_DIR) $(TARGET)

.PHONY: all clean install uninstall

