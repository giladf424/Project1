#pragma once
#ifndef FILGHT
#define FILGHT
#include <string.h>
#include <stdlib.h>
#include "Plane.h"
#include "Airport.h"
#include "Date.h"
#include "AirportManager.h"

typedef struct {
    char origin[CODE + 1];
    char destination[CODE + 1];
    Plane plane;
    Date date;
}Flight;

void initFlight(Flight* f, Plane* plane, AirportManager* apm);

int isFlightFromSourceAirport(const Flight* f, char* originCode);

int isFlightToDestAirport(const Flight* f, char* destCode);

int isPlaneTypeInFlight(const Flight* f, planeType type);

int getAirportsForFlight(Flight* f, AirportManager* apm);

void printFlight(Flight* const f);

void freeFlight(Flight* f);

void tempFunction(Flight* f, AirportManager* apm);
#endif // !FILGHT
