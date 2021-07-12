#include "Ticket.h"

void TicketList_Initialize(TicketList** ticketList){
  (*ticketList) = malloc(sizeof(TicketList));
  (*ticketList)->length=0;
  (*ticketList)->top=NULL;
}
void TicketList_Destroy(TicketList* ticketList){
  Ticket* ticket = NULL;
  for(int i=0; i<ticketList->length; i++){
    ticket = ticketList->top;
    ticketList->top=ticket->next;

    free(ticket->name);
    free(ticket);
  }
  free(ticketList);
}
void TicketList_AddTicket(TicketList* ticketList, MovieList* movieList, char* name, int seats, bool paid){
  if(!ticket_movie_exists_in_movie_list(movieList, name)){
    fprintf(stdout,"No such movie in the list of movies.\n");
    return;
  }

  Movie* movie = movieList->top;
  int capacity=-1;
  for(int i=0; i<movieList->length; i++){
    if(strcmp(name,movie->name)==0){
      capacity=movie->capacity;
      break;
    }
    movie=movie->next;
  }
  if(capacity<seats){
    fprintf(stdout,"\"%s\" only has %d tickets left.\n",name,capacity);
    return;
  }


  Ticket *ticket = malloc(sizeof(Ticket));
  ticket->name = malloc(sizeof(char)*strlen(name) + 1);
  memset(ticket->name, 0, strlen(name) + 1);

  strcpy(ticket->name,name);
  ticket->ticket_price = get_movie_price(movieList, name);
  ticket->seats = seats;
  movie->capacity -= seats;
  ticket->paid=paid;

  ticket->next = ticketList->top;
  ticketList->top = ticket;
  ticketList->length++;
  return;
}

void TicketList_CancelTicket(TicketList* ticketList, MovieList* movieList, char* name){
  if(ticketList->length==0){
    fprintf(stdout,"You have not booked any ticket yet.\n");
    return;
  }
  Ticket* ticket = ticketList->top;
  Ticket* prevTicket = ticketList->top;
  for(int i=0; i<ticketList->length; i++){
    if(strcmp(ticket->name, name)==0){

      // Find the movie in the movie list and change movie->capacity
      Movie* movie = movieList->top;
      for(int i=0; i<movieList->length; i++){
        if(strcmp(movie->name, name)==0){
          movie->capacity+=ticket->seats;
          break;
        }
        movie=movie->next;
      }

      if(i==0){
        ticketList->top = ticket->next;
      }
      prevTicket->next = ticket->next;
      ticketList->length--;

      fprintf(stdout,"\"%s\" has been deleted.\n",ticket->name);

      //free(ticket->name);
      free(ticket);
      return;
    }
    ticket = ticket->next;
    if(i!=0) prevTicket = prevTicket->next;
  }
  fprintf(stdout, "You have not booked any ticket for \"%s\"\n", ticket->name);
  return;
}

// aasdsdasdsad
void TicketList_Save(TicketList* ticketList, char* username){
  char filename[BUFFER_SIZE];
  memset(filename, 0, BUFFER_SIZE);

  strcat(filename, "./Users/");
  strcat(filename, username);
  strcat(filename, ".txt");


  FILE* file = fopen(filename, "w");
  if(file==NULL){
    fprintf(stdout, "Error opening the file to save ticket list.\n");
    return;
  }
  TicketList_Print(ticketList, file);
  fclose(file);
}

 void TicketList_Print(TicketList* ticketList, FILE* stream){
   if(ticketList->length==0){
     fprintf(stdout, "The ticket list is empty\n");
     return;
   }
   Ticket* ticket = ticketList->top;
   for(int i=0; i<ticketList->length; i++){
     fprintf(stream, "%s-%d-%d-%d\n",ticket->name, ticket->ticket_price, ticket->seats, ticket->paid);
     ticket = ticket->next;
   }
   return;
 }

void TicketList_Load(TicketList* ticketList, MovieList* movieList, char* username){
  char filename[BUFFER_SIZE];
  memset(filename, 0, BUFFER_SIZE);

  strcat(filename, "./Users/");
  strcat(filename, username);
  strcat(filename, ".txt");
   FILE* file = fopen(filename, "r");
   if(file==NULL){
     fprintf(stdout, "The ticket list for user %s, is empty\n",username);
     return;
   }
   char buffer[BUFFER_SIZE];
   memset(buffer, 0, BUFFER_SIZE);

   while(fgets(buffer, BUFFER_SIZE, file)!=NULL){
   char* name = strtok(buffer, DELIM);
   int ticket_price = atoi(strtok(NULL, DELIM));
   int seats = atoi(strtok(NULL, DELIM));
   bool paid = atoi(strtok(NULL, DELIM));
   //TicketList_AddTicket(ticketList, movieList, name, seats, paid);
   Ticket *ticket = malloc(sizeof(Ticket));
   ticket->name = malloc(sizeof(char)*strlen(name) + 1);
   memset(ticket->name, 0, strlen(name) + 1);

   strcpy(ticket->name,name);
   ticket->ticket_price = get_movie_price(movieList, name);
   ticket->seats = seats;
   ticket->paid=paid;
   ticket->next = ticketList->top;
   ticketList->top = ticket;
   ticketList->length++;

   }
   fclose(file);
 }
