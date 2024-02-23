#pragma once
#ifndef AIRPORT
#define AIRPORT
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "generalFunctions.h"
#include <stdlib.h>
#include <ctype.h>
#define CODE 3

typedef struct {
    char* name;
    char* country;
    char code[CODE + 1];
} Airport;

Airport* initAirport(Airport* port);

void getAirportCode(char* airportCode);

Airport* initAirportNoCode(Airport* port);

void getAirportName(Airport* port);

char* makeNameAirporti(char* name);

void getAirportCountry(Airport* port);

void printAirport(Airport const* port);

void freeAirport(Airport* port);

char* makeSpacesAndNameGood(char* formatName, int wc);

int isSameAirport(Airport* const port1, Airport* const port2);

int isAirportCode(Airport* const port, char* code);


#endif // !AIRPORT
