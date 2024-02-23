#include "Airline.h"

void initAirline(Airline* airline) {
    char* name = initAirlineName();
    airline->name = name;
    airline->planeArr = NULL;
    airline->flights = NULL;
    airline->planeCount = 0;
    airline->flightCount = 0;

}

char* initAirlineName() {
    char name[MAX_LENGTH] = { 0 };
    printf(" Enter Airline name    \n");
    myGets(name, MAX_LENGTH);
    char* rname = malloc(strlen(name));
    strcpy(rname, name);
    //hey

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
    int sn;
    printf("Choose a plane from list, type its serial Number\n");
    printPlanesArr(airline->planeArr, airline->planeCount);

    Plane* p = NULL;
    do {
        scanf("%d", &sn);
        p = findPlaneBySn(airline, sn);
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
    printf(" -------- Has %d plane", airline->planeCount);
}

int addFlight(Airline* airline, AirportManager* apm) {
    if (apm->numOfAirports <= 1) {
        printf("There are not enough airport to add flight");
        return 0;
    }
    else if (airline->planeCount == 0) {
        printf("There is no plane in company");
        return 0;
    }
    else {
        printAirports(apm);
        Flight* f = malloc(sizeof(Flight));
        Plane* p = findPlane(airline);
        initFlight(f, p, apm);
        airline->flightCount++;
    }
    return 1;
}

void doPrintFlightsWithPlaneType(Airline* const airline) {
    planeType type = getPlaneType();
    for (int i = 0; i < airline->planeCount; i++) {
        if (airline->planeArr[i].type == type) {
            printPlane(&airline->planeArr[i]);
        }
    }
}
