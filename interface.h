#ifndef _INTERFACEH_
#define _INTERFACEH_

#include "Auxiliary.h"
#include "Movie.h"
#include "Ticket.h"
#include<stdbool.h>

// Global Variable
char buffer[BUFFER_SIZE];
void admin_interface(MovieList*);
void user_interface(MovieList*, TicketList*);
void moderator_interface(MovieList* , TicketList* );


#endif
