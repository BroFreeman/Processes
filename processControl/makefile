assign5 : main.o assign5.o
	gcc assign5.o main.o -o assign5

main.o : main.c assign5.h
	gcc -Wall -c main.c

assign5.o : assign5.c assign5.h
	gcc -Wall -c assign5.c

clean :
	rm *.o assign5
