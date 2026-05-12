CC = gcc

CFLAGS = -Wall -Wextra -Werror -std=c11

TARGET = apc

SRC = main.c \
      apc.c \
      add.c \
      sub.c \
      mul.c \
      div.c \
      utils.c

OBJ = $(SRC:.c=.o)

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJ)

%.o: %.c apc.h
	$(CC) $(CFLAGS) -c $< -o $@

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f *.o $(TARGET)

rebuild: clean all