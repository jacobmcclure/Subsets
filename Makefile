Subset: Subset.o
	gcc -o Subset Subset.o
Subset.o: Subset.c
	gcc -c -std=c99 -Wall Subset.c
clean :
	rm -f Subset Subset.o

