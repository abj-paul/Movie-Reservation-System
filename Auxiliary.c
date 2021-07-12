#include "Auxiliary.h"

void input(char* buffer){
  memset(buffer, 0, BUFFER_SIZE);
  fgets(buffer, BUFFER_SIZE, stdin);

  FILE* test = fopen("test.txt","w");
  fprintf(test,"%s",buffer);
  strtok(buffer,"\n");
}


// TESTING
/*
void main(){
  char x[BUFFER_SIZE];
  input_string(x);
}
*/
