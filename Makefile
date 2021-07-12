all: main.o Movie.o Auxiliary.o interface.o Ticket.o
	@echo '*Compiling program from object files.'
	@gcc -o launcher main.o Movie.o Auxiliary.o interface.o Ticket.o
Movie.o: Movie.c
	@echo '*Compiling Movie'
	@gcc -c Movie.c
main.o: main.c
	@echo "*Compiling main"
	@gcc -c main.c
Auxiliary.o: Auxiliary.c
	@echo "*Compiling Auxiliary"
	@gcc -c Auxiliary.c
interface.o: interface.c
	@echo "*Compiling interface"
	@gcc -c interface.c
Ticket.o: Ticket.c
	@echo "*Compiling Ticket"
	@gcc -c Ticket.c
clean:
	@echo "Cleaning Objects"
	@rm -f *.o Users/* Movie_list.txt
