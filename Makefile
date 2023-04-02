gcc=gcc -Wall -Wextra -Werror -pedantic -std=c11 -Wno-format -Iinc

main: main.o successful_pairs.o three_sum_closest.o three_sum.o
	$(gcc) bin/main.o bin/successful_pairs.o bin/three_sum_closest.o bin/three_sum.o -o main


main.o: src/main.c
	$(gcc) -c src/main.c  -o bin/main.o

successful_pairs.o: inc/successful_pairs.c
	$(gcc) -c inc/successful_pairs.c -o bin/successful_pairs.o

three_sum_closest.o: inc/three_sum_closest.c
	$(gcc) -c inc/three_sum_closest.c -o bin/three_sum_closest.o

three_sum.o: inc/three_sum.c
	$(gcc) -c inc/three_sum.c -o bin/three_sum.o


launch: main
	./main

clean:
	rm -f main bin/*.o
