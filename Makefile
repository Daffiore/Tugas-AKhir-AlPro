CC = gcc
CFLAGS = -Wall -Wextra

all: parkir

parkir: parkir.c
	$(CC) $(CFLAGS) parkir.c -o parkir

clean:
	rm -f parkir parkir.exe