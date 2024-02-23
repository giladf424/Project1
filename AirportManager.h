#ifndef AIRPORTMANAGER
#define AIRPORTMANAGER
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "Airport.h"
#include "Plane.h"
#include "Date.h"

typedef struct {
    Airport** theAirports;
    int numOfAirports;
} AirportManager;

void initManager(AirportManager* apm);

int addAirport(AirportManager* apm);

void freeManager(AirportManager* apm);

void printAirports(AirportManager* const apm);

int isAirportCodeInUse(char* code, AirportManager* const apm);

Airport* findAirportByCode(AirportManager* apm, char* code);

#endif // !AIRPORTMANAGER