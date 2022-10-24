CC = gcc
CFLAGS = -Wall -Werror -Wextra

cipher: cipher.o
	$(CC) cipher.o -o ../build/cipher

dmanager_module.o: cipher.c
	$(CC) $(CFLAGS) -c cipher.c

clean:
	rm -rf ../build/cipher *.o

rebuild:
	clean cipher