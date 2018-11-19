all:lionel

file.o: file.h file.c types.h
	gcc -c file.c -Wall -Wextra


server.o: server.h server.c types.h
	gcc -c server.c -Wall -Wextra

main.o: main.c types.h server.h file.h
	gcc -c main.c -Wall -Wextra


lionel: file.o server.o main.o
	gcc file.o server.o main.o -o lionel

clean:
	rm -f *.o lionel
