#ifndef _AUXILIARYH_
#define _AUXILIARYH_

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define BUFFER_SIZE 612
enum MODES{ADMIN, MODERATOR, USER};
#define DELIM "\n-"

void input(char* buffer);

#endif
