project1: userinterface.o database.o record.h prototypes.h
	gcc -o project1 userinterface.o database.o

database.o: database.c
	gcc -c database.c

userinterface.o: userinterface.c
	gcc -c userinterface.c

clean: 
	rm project1 userinterface.o database.o 