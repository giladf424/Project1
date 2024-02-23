#include "Airline.h"
#include <stdlib.h>
#include <string.h>

Airline* initAirline(Airline* airline) {
    char* name = initAirlineName();
    airline->name = name;
    airline->planeArr = NULL;
    airline->flights = NULL;
    airline->planeCount = 0;
    airline->flightCount = 0;

    return airline;
}

char* initAirlineName() {
    char name[MAX_LENGTH];
    printf("Enter Airline name\n");
    myGets(name, MAX_LENGTH);
    char* rname = malloc(strlen(name));
    strcpy(rname, name);

    return rname;
}

int addPlane(Airline* airline) {
    airline->planeCount++;
    airline->planeArr = realloc(airline->planeArr, airline->planeCount * sizeof(Plane));
    initPlane(&airline->planeArr[airline->planeCount - 1], airline->planeArr, airline->planeCount);
    return 1;
}

void printPlanesArr(Plane* planeArr, int s) {
    for (int i = 0; i < s; i++) {
        printPlane(&planeArr[i]);
        printf("\n");
    }
}

void printFlights(Flight** flights, int flightCount) {
    for (int i = 0; i < flightCount; i++) {
        printFlight(flights[i]);
        printf("\n");
    }
}

void freeCompany(Airline* airline) {
    free(airline->name);
    free(airline->planeArr);
    for (int i = 0; i < airline->flightCount; i++) {
        free(airline->flights[i]);
    }
}

Plane* findPlane(Airline* airline) {
    char sn[MAX_LENGTH];
    printf("\nChoose a plane from list, type its serial Number\n");
    printPlanesArr(airline->planeArr, airline->planeCount);

    Plane* p = NULL;
    do {
        myGets(sn, MAX_LENGTH);
        for (int i = 1; i < (int)strlen(sn); i++) {
            if (!isdigit(sn[i])) {
                printf("Invalid input! Try again!\n");
                return NULL;
            }
        }
        int snInt = atoi(sn);
        p = findPlaneBySn(airline, snInt);
    } while (!p);
    return p;
}

Plane* findPlaneBySn(Airline* airline, int sn) {
    for (int i = 0; i < airline->planeCount; i++) {
        if ((airline->planeArr[i].serialNum) == sn)
            return &airline->planeArr[i];
    }
    printf("No plane with that serial number! Try again!\n");
    return NULL;
}

void printCompany(Airline* const airline) {
    printf("\nAirline %s\n", airline->name);
    printf(" -------- Has %d planes\n", airline->planeCount);
    printPlanesArr(airline->planeArr, airline->planeCount);
    printf("\n -------- Has %d flights\n", airline->flightCount);
    printFlights(airline->flights, airline->flightCount);
}

int addFlight(Airline* airline, AirportManager* apm) {
    if (apm->numOfAirports <= 1) {
        printf("There are not enough airport to set a flight\n");
        return 0;
    }
    else if (airline->planeCount == 0) {
        printf("There is no plane in company");
        return 0;
    }
    else {
        Flight* f = malloc(sizeof(Flight));
        Plane* p = findPlane(airline);
        printAirports(apm);
        initFlight(f, p, apm);
        airline->flightCount++;
        airline->flights = realloc(airline->flights, airline->flightCount * sizeof(Flight*));
        airline->flights[airline->flightCount - 1] = f;
    }
    return 1;
}

void doPrintFlightsWithPlaneType(Airline* const airline) {
    planeType type = getPlaneType();
    printf("\nFlights with plane type %s:\n", planeTypeStr[type]);
    for (int i = 0; i < airline->flightCount; i++) {
        if (airline->flights[i]->plane.type == type) {
            printFlight(airline->flights[i]);
        }
    }
}