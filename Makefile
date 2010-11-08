stringevolver:main.o
	gcc -o stringevolver main.o

main.o:src/main.c
	gcc -c -g src/main.c
clean:
	rm -rf *.o
