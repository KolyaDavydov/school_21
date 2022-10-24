CC = gcc
CFLAGS = -Wall -Werror -Wextra

state_sort: state_sort.o
	$(CC) state_sort.o -o ../build/Quest_1

state_sort.o: state_sort.c
	$(CC) $(CFLAGS) -c state_sort.c

clean:
	rm -rf ../build/Quest_1 *.o

rebuild:
	clean state_sort