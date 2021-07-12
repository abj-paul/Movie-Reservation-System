#ifndef _MOVIEH_
#define _MOVIEH_

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#include "Auxiliary.h"

typedef struct Movie{
  char* name;
  int price;
  int capacity;
  struct Movie* next;
} Movie;

typedef struct MovieList{
  int length;
  struct Movie* top;
} MovieList;

// Initialize Movie List
void MovieList_Initialize(MovieList**);
// Clear the heap before closing the progeam.
void MovieList_Destroy(MovieList*);
// Add a new movie to the list
void MovieList_AddMovie(MovieList* , char* , int , int );
// Delete a movie from the list
void MovieList_DeleteMovie(MovieList* , char* );
// Save movie in the file
void MovieList_Save(MovieList* , char* );
// Load Movie List
void MovieList_Load(MovieList* );
// Print movie list in the stream
void MovieList_Print(MovieList* , FILE* );


// Auxiliary Functions
int get_movie_price(MovieList*, char*);
int ticket_movie_exists_in_movie_list(MovieList*, char*);

#endif
