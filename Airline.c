#include "Airline.h"
#include <stdlib.h>
#include <string.h>

void initAirline(Airline* airline) {
    char* name;
    do
    {
        name = initAirlineName();
    } while (!name);
    airline->name = name;
    airline->planeArr = NULL;
    airline->flights = NULL;
    airline->planeCount = 0;
    airline->flightCount = 0;

}

char* initAirlineName() {
    char* rname;
    char name[MAX_LENGTH];
    printf("Enter Airline name\n");
    myGets(name, MAX_LENGTH);
    rname = (char*)malloc((strlen(name) +1)*sizeof(char));
    if (!rname)
        return NULL;
    strcpy(rname, name);

    return rname;
}

int addPlane(Airline* airline) {
    airline->planeArr = (Plane*)realloc(airline->planeArr, (airline->planeCount + 1) * sizeof(Plane));
    if (!airline->planeArr)
        return 0;
    initPlane(&airline->planeArr[airline->planeCount], airline->planeArr, airline->planeCount);
    airline->planeCount++;
    return 1;
}

void printPlanesArr(const Plane* planeArr, int s) {
    for (int i = 0; i < s; i++) {
        printPlane(&planeArr[i]);
        printf("\n");
    }
}

void printFlights(const Flight** flights, int flightCount) {
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
    free(airline->flights);
}

Plane* findPlane(Airline* airline) {
    char sn[MAX_LENGTH];
    printf("\nChoose a plane from list, type its serial Number\n");
    printPlanesArr(airline->planeArr, airline->planeCount);

    Plane* p = NULL;
    do {
        myGets(sn, MAX_LENGTH);
        for (int i = 0; i < (int)strlen(sn); i++) {
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

void printCompany(const Airline* airline) {
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
        Flight* f = (Flight*)malloc(sizeof(Flight));
        if (!f)
            return 0;
        Plane* p = findPlane(airline);
        printAirports(apm);
        initFlight(f, p, apm);
        airline->flights = (Flight**)realloc(airline->flights, (airline->flightCount +1) * sizeof(Flight*));
        if (!airline->flights)
            return 0;
        airline->flights[airline->flightCount] = f;
        airline->flightCount++;
    }
    return 1;
}

void doPrintFlightsWithPlaneType(const Airline* airline) {
    planeType type = getPlaneType();
    printf("\nFlights with plane type %s:\n", planeTypeStr[type]);
    for (int i = 0; i < airline->flightCount; i++) {
        if (airline->flights[i]->plane.type == type) {
            printFlight(airline->flights[i]);
        }
    }
    printf("\n");
}