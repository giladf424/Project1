#ifndef GENERALFUNCTIONS
#define  GENERALFUNCTIONS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_LENGTH 255

char* rmWhiteSpace(char* name);

int wordCount(char* str);

char* cleanWhiteSpaceEdges(char* str);

char* addUnderlines(char* formatName);

char* myGets(char* buffer, int size);

char* getStrExactLength(const char* msg);

#endif // !GENERALFUNCTIONS