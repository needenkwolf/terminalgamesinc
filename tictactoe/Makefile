CC = gcc
WINCC = x86_64-w64-mingw32-gcc
CFLAGS = -Wall -Wextra -pedantic

SRC = $(wildcard *.c)

linux: $(SRC)
	$(CC) $(CFLAGS) $^ -o tictactoe.out

windows: $(SRC)
	$(WINCC) $(CFLAGS) $^ -o tictactoe.exe
