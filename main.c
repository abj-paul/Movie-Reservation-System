#include "Movie.h"
#include "interface.h"
#include "Ticket.h"

int main(int argc, char* argv[]){
  if(argc>2){
    fprintf(stdout, "Use -h for information and help about the program.\n");
    return -1;
  }

  int mode=-1;
  if(argc==1){
    //default
    mode=USER;
  }
  else if(strcmp(argv[1],"-u")==0) mode = USER;
  else if(strcmp(argv[1],"-m")==0) mode = MODERATOR;
  else if(strcmp(argv[1],"-a")==0) mode = ADMIN;
  else{
    fprintf(stdout, "Invalid additive. Use -h for information and help about the program.\n");
    return -1;
  }
  // Initialization
  MovieList* movieList;
  MovieList_Initialize(&movieList);
  MovieList_Load(movieList);

  TicketList* ticketList;
  TicketList_Initialize(&ticketList);

  switch(mode){
    case ADMIN:
      admin_interface(movieList);
      break;
    case MODERATOR:
      moderator_interface(movieList, ticketList);
      break;
    case USER:
      user_interface(movieList, ticketList);
      break;
  }


  TicketList_Destroy(ticketList);
  MovieList_Destroy(movieList);
  return 0;
}
