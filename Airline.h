#ifndef AIRLINE
#define AIRLINE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "AirportManager.h"
#include "Plane.h"
#include "Flight.h"
#include "generalFunctions.h"

typedef struct {
    char* name;
    Plane* planeArr;
    Flight** flights;
    int planeCount;
    int flightCount;
} Airline;

void initAirline(Airline* airline);

char* initAirlineName();

int addPlane(Airline* airline);

void printPlanesArr(Plane* planes, int planeCount);

void printFlights(Flight** flights, int flightCount);

void printAirline(Airline* const airline);

void freeCompany(Airline* airline);

Plane* findPlane(Airline* airline);

Plane* findPlaneBySn(Airline* airline, int sn);

void printCompany(Airline* const airline);

int addFlight(Airline* airline, AirportManager* apm);

void doPrintFlightsWithPlaneType(Airline* const airline);

#endif // !AIRLINE