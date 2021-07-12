#ifndef _TICKETH_
#define _TICKETH_

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

#include "Movie.h"
#include "Auxiliary.h"

typedef struct Ticket{
  char* name;
  int ticket_price;
  int seats;
  bool paid;
  struct Ticket* next;
} Ticket;

typedef struct TicketList{
  int length;
  struct Ticket* top;
} TicketList;

// Initialize Ticket List
void TicketList_Initialize(TicketList**);
// Clear the heap before closing the progeam.
void TicketList_Destroy(TicketList*);
// Add a new movie to the list
void TicketList_AddTicket(TicketList* ,MovieList* ,char* , int, bool);
// Delete a movie from the list
void TicketList_CancelTicket(TicketList* ,MovieList*, char* );
// Save movie in the file
void TicketList_Save(TicketList* , char* );
// Load Ticket List
void TicketList_Load(TicketList*, MovieList*, char* );
// Print movie list in the stream
void TicketList_Print(TicketList* , FILE* );

#endif
