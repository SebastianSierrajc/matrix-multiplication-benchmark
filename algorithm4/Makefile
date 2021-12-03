GCC = gcc
FLAGS = -ansi -std=c99 -pedantic -Wall -fopenmp
CFLAG = -lm
PROGRAMS = MM1c

MM1c:
	$(GCC) $(FLAGS) matrixUtils/matrixUtils.c -c -o matrixUtils/matrixUtils.o
	$(GCC) $(FLAGS) benchmarkUtils/timeUtils.c -c -o benchmarkUtils/timeUtils.o
	$(GCC) $(FLAGS) $@.c -c
	$(GCC) $(FLAGS) -o $@.out $@.o matrixUtils/matrixUtils.o benchmarkUtils/timeUtils.o

clean:
	$(RM) $(PROGRAMS) *.o *.out */*.o outputs/*.txt
