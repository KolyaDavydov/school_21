CC = gcc
CFLAGS = -Wall -Werror -Wextra

door_struct: dmanager_module.o
	$(CC) dmanager_module.o -o ../build/Quest_1

dmanager_module.o: dmanager_module.c
	$(CC) $(CFLAGS) -c dmanager_module.c

clean:
	rm -rf ../build/Quest_1 *.o

rebuild:
	clean door_struct