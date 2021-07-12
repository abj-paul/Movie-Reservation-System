#include "interface.h"


void admin_interface(MovieList* movieList){
  fprintf(stdout,"Entering Admin Mode.\n");
      int exit = 0;
      while(!exit){
        fprintf(stdout, "1. View Movies.\n");
        fprintf(stdout, "2. Add New Movie.\n");
        fprintf(stdout, "3. Delete A Movie\n");
        fprintf(stdout, "4. Exit\n");

        fprintf(stdout, "> ");
        input(buffer);
        int command = atoi(buffer);
        switch(command){
        case 1: // view movies
          MovieList_Print(movieList, stdout);
          break;
        case 2: // Add new movie
          fprintf(stdout, "Name of the movie: ");
          char name[BUFFER_SIZE];
          int price, capacity;

          input(name);
          fprintf(stdout, "Price of a \"%s\" ticket: ",name);
          input(buffer);
          price = atoi(buffer);
          fprintf(stdout, "Capacity: ");
          input(buffer);
          capacity = atoi(buffer);
          MovieList_AddMovie(movieList, name, price, capacity);
          break;
        case 3: // Delete a movie
          fprintf(stdout, "Enter the name of the movie to delete: ");
          input(buffer);
          MovieList_DeleteMovie(movieList, buffer);
          break;
        case 4:
          fprintf(stdout,"Saving and Exiting program.\n");
          exit = 1;
          MovieList_Save(movieList, "Movie_list.txt");
          break;
        }
      }
}


void user_interface(MovieList* movieList, TicketList* ticketList){
 fprintf(stdout,"Entering User Mode.\n");
 fprintf(stdout,"Username: ");
 char username[BUFFER_SIZE];
 input(username);
 TicketList_Load(ticketList, movieList, username);

      int exit = 0;
      while(!exit){
        fprintf(stdout, "1. View Movies.\n");
        fprintf(stdout, "2. Book a Ticket.\n");
        fprintf(stdout, "3. Delete A Ticket.\n");
        fprintf(stdout, "4. View Booked Tickets.\n");
        fprintf(stdout, "5. Exit.\n");

        fprintf(stdout, "> ");
        input(buffer);
        int command = atoi(buffer);

        switch(command){
        case 1: // view movies
          MovieList_Print(movieList, stdout);
          break;
        case 2: // Book a ticket
          fprintf(stdout, "Name of the movie: ");
          char name[BUFFER_SIZE];
          int seats=-1;
          bool paid=false;
          input(name);

          fprintf(stdout, "Number of seats for \"%s\": ",name);
          input(buffer);
          seats = atoi(buffer);

          fprintf(stdout, "Pay Method: (1)Cinema Hall. (2)Online\nHow will you pay? ");
          input(buffer);
          paid = atoi(buffer) - 1;

          TicketList_AddTicket(ticketList ,movieList, name, seats, paid);
          break;
        case 3: // Delete a ticket
          fprintf(stdout, "Enter the name of movie of the ticket to delete: ");
          input(buffer);
          TicketList_CancelTicket(ticketList, movieList, buffer);
          break;
        case 4:
          TicketList_Print(ticketList, stdout);
          break;
        case 5: // Exiting
          fprintf(stdout,"Saving and Exiting program.\n");
          exit = 1;
          TicketList_Save(ticketList, username);
          MovieList_Save(movieList, "Movie_list.txt");
          break;
        }
      }

}

void moderator_interface(MovieList* movieList, TicketList* ticketList){
  fprintf(stdout,"Entering Moderator Mode.\n");
  char username[BUFFER_SIZE];

  int exit = 0;
      while(!exit){
        fprintf(stdout, "1. New Session for User.\n");
        fprintf(stdout, "2. Book a Ticket.\n");
        fprintf(stdout, "3. Cancel A Ticket.\n");
        fprintf(stdout, "4. View Booked Tickets.\n");
        fprintf(stdout, "5. Exit.\n");

        fprintf(stdout, "> ");
        input(buffer);
        int command = atoi(buffer);

        switch(command){
        case 1: // take username
          fprintf(stdout,"Username: ");
          input(username);
          TicketList_Load(ticketList, movieList, username);

          break;
        case 2: // Book a ticket
          fprintf(stdout, "Name of the movie: ");
          char name[BUFFER_SIZE];
          int seats=-1;
          bool paid=false;
          input(name);

          fprintf(stdout, "Number of seats for \"%s\": ",name);
          input(buffer);
          seats = atoi(buffer);

          fprintf(stdout, "Pay Method: (1)Cinema Hall. (2)Online\nHow will you pay? ");
          input(buffer);
          paid = atoi(buffer) - 1;

          TicketList_AddTicket(ticketList ,movieList, name, seats, paid);
          break;
        case 3: // Delete a ticket
          fprintf(stdout, "Enter the name of movie of the ticket to delete: ");
          input(buffer);
          TicketList_CancelTicket(ticketList, movieList, buffer);
          break;
        case 4:
          TicketList_Print(ticketList, stdout);
          break;
        case 5: // Exiting
          fprintf(stdout,"Saving and Exiting program.\n");
          exit = 1;
          TicketList_Save(ticketList, username);
          MovieList_Save(movieList, "Movie_list.txt");
          break;
        }
      }

}
