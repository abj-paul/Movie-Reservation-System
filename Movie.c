#include "Movie.h"
#include "Auxiliary.h"

void MovieList_Initialize(MovieList** movieList){
  (*movieList) = malloc(sizeof(MovieList));
  (*movieList)->length=0;
  (*movieList)->top=NULL;
}
void MovieList_Destroy(MovieList* movieList){
  Movie* movie = NULL;
  for(int i=0; i<movieList->length; i++){
    movie = movieList->top;
    movieList->top=movie->next;

    free(movie->name);
    free(movie);
  }
  free(movieList);
}


void MovieList_AddMovie(MovieList* movieList, char* name, int price, int capacity){
  Movie *movie = malloc(sizeof(Movie));
  movie->name = malloc(sizeof(char)*strlen(name) + 1);
  memset(movie->name, 0, strlen(name) + 1);
  strcpy(movie->name,name);
  movie->price = price;
  movie->capacity = capacity;
  movie->next = movieList->top;
  movieList->top = movie;
  movieList->length++;
  return;
}

void MovieList_DeleteMovie(MovieList* movieList, char* name){
  if(movieList->length==0){
    fprintf(stdout,"No movies are being premiered.\n");
    return;
  }
  Movie* movie = movieList->top;
  Movie* prevMovie = movieList->top;
  for(int i=0; i<movieList->length; i++){
    if(strcmp(movie->name, name)==0){
      if(i==0){
        movieList->top = movie->next;
      }
      prevMovie->next = movie->next;
      movieList->length--;

      fprintf(stdout,"\"%s\" has been deleted.\n",movie->name);

      //free(movie->name);
      free(movie);
      return;
    }
    movie = movie->next;
    if(i!=0) prevMovie = prevMovie->next;
  }
  fprintf(stdout, " \"%s\" is not in the list of movies.\n", movie->name);
  return;
}
void MovieList_Save(MovieList* movieList, char* filename){
  FILE* file = fopen(filename, "w");
  if(file==NULL){
    fprintf(stdout, "Error opening the file to save movie list.\n");
    return;
  }
  MovieList_Print(movieList, file);
  fclose(file);
}

 void MovieList_Print(MovieList* movieList, FILE* stream){
   if(movieList->length==0){
     fprintf(stdout, "The movie list is empty\n");
     return;
   }
   Movie* movie = movieList->top;
   for(int i=0; i<movieList->length; i++){
     fprintf(stream, "%s-%d-%d\n",movie->name, movie->price, movie->capacity);
     movie = movie->next;
   }
   return;
 }

 void MovieList_Load(MovieList* movieList){
   FILE* file = fopen("Movie_list.txt", "r");
   if(file==NULL){
     fprintf(stdout, "The movie list is empty\n");
     return;
   }
   char buffer[BUFFER_SIZE];
   memset(buffer, 0, BUFFER_SIZE);

   while(fgets(buffer, BUFFER_SIZE, file)!=NULL){
   char* name = strtok(buffer, DELIM);
   int price = atoi(strtok(NULL, DELIM));
   int capacity = atoi(strtok(NULL, DELIM));
   //MovieList_AddMovie(movieList, name, price, capacity);
   Movie *movie = malloc(sizeof(Movie));
   movie->name = malloc(sizeof(char)*strlen(name) + 1);
   memset(movie->name, 0, strlen(name) + 1);
   strcpy(movie->name,name);
   movie->price = price;
   movie->capacity = capacity;
   movie->next = movieList->top;
   movieList->top = movie;
   movieList->length++;

   }
   fclose(file);
 }


int get_movie_price(MovieList* movieList, char* name){
  if(movieList->length==0){
    return -1;
  }
  Movie* movie=movieList->top;
  for(int i=0; i<movieList->length; i++){
    if(strcmp(name, movie->name)==0){
      return movie->price;
    }
    movie=movie->next;
  }
  return -1;
}

int ticket_movie_exists_in_movie_list(MovieList* movieList, char* name){
  if(movieList->length==0){
    return 0;
  }
  Movie* movie=movieList->top;
  for(int i=0; i<movieList->length; i++){
    if(strcmp(name, movie->name)==0){
      return 1;
    }
    movie=movie->next;
  }
  return 0;

}
