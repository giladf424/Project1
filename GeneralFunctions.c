#include "GeneralFunctions.h"
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

int wordCount(char* str) {
    if (strlen(str) == 1) {
        return isspace(*str);
    }
    int wc = 1;
    for (int i = 1; i < (int)strlen(str); i++) {
        if (*(str + i) == ' ' && (*(str + i - 1) != ' ')) {
            wc++;
        }
    }
    return wc;
}

char* cleanWhiteSpaceEdges(char* str) {
    char* stret = str;
    int i = 0, j = (int)strlen(str);
    while (*(str + j - 1) == ' ') {
        j--;
    }
    while (*(str + i) == ' ') {
        i++;
    }
    stret = malloc(j - i + 1);
    if (!stret)
        return NULL;
    strncpy(stret, str + i, j - i);
    *(stret + j - i) = '\0';
    return stret;
}

char* addUnderlines(char* formatName) {
    int l = (int)strlen(formatName) * 2 - 1;
    formatName =  (char*)realloc(formatName, l);
    if (!formatName)
        return NULL;
    for (int i = (int)strlen(formatName) - 1, j = l - 1; i >= 0; j--, i--) {
        *(formatName + j) = (*(formatName + i) >= 97) ? *(formatName + i) - 32 : *(formatName + i);
        j--;
        *(formatName + j) = '_';
    }
    *(formatName + l) = '\0';

    return formatName;
}

char* rmWhiteSpace(char* name) {
    char* formatName = (char*)malloc(strlen(name));
    if (!formatName)
        return NULL;
    strcpy(formatName, name);
    for (int i = 0, j = 0; j < (int)strlen(formatName); j++, i++) {
        if (isspace(*(formatName + i))) {
            do {
                i++;
            } while (isspace(*(formatName + i)));
        }
        if (i != j) {
            *(formatName + j) = *(formatName + i);
        }
    }
    return formatName;
}

char* myGets(char* buffer, int size)
{
    char* ok;
    if (buffer != NULL && size > 0)
    {
        do {
            ok = fgets(buffer, size, stdin);
        } while (ok && ((strlen(buffer) <= 1) && (isspace(buffer[0]))));
        if (ok)
        {
            char* back = buffer + strlen(buffer);
            //trim end spaces
            while ((buffer < back) && (isspace(*--back)));
            *(back + 1) = '\0';
            return buffer;
        }
        buffer[0] = '\0';
    }
    return NULL;
}

char* getStrExactLength(const char* msg)
{
    char* theStr = NULL;
    size_t len;
    char inpStr[MAX_LENGTH]; //variable to hold the string that the user gives

    //Ask for a string from the user
    puts(msg);
    if (!myGets(inpStr, sizeof(inpStr)))
        return NULL;

    //find string size and add 1 for the '\0'
    len = strlen(inpStr) + 1;
    //allocate a place for the string in the right location in the array 
    theStr = (char*)malloc(len * sizeof(char));
    //Copy the string to the right location in the array 
    if (theStr != NULL)
        strcpy(theStr, inpStr);

    //can use the strdup function replace line 20 to 25
    //theStr = strdup(inpStr);
    return theStr;
}