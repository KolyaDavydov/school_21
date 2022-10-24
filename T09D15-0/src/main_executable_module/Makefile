all: build

build: main_executable_module.o data_io.o data_stat.o data_process.o decision.o
	gcc main_executable_module.o data_io.o data_stat.o data_process.o decision.o -o ../../build/Quest_3

main_executable.o: main_executable_module.c
	gcc -c main_executable_module.c

data_io.o: ../data_libs/data_io.c
	gcc -c ../data_libs/data_io.c

data_stat.o: ../data_libs/data_stat.c
	gcc -c ../data_libs/data_stat.c

data_process.o: ../data_module/data_process.c
	gcc -c ../data_module/data_process.c

decision.o: ../yet_another_decision_module/decision.c
	gcc -c ../yet_another_decision_module/decision.c

clean:
	rm -rf ../../build/Quest_3 *.o

