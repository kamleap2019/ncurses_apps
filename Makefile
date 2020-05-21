CC = gcc
CFLAGS = -Wall -I .
LDFLAGS = -l ncurses
RM = rm
SRC=sirepinski_lj.c
TARGET=sirepinski.out

$(TARGET) : $(SRC)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $(TARGET) $(SRC)
.PHONY: clean

clean:
	$(RM) $(TARGET)