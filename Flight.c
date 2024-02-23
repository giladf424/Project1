#include "Flight.h"
#include "generalFunctions.h"

void initFlight(Flight* f, Plane* plane, AirportManager* apm) {
    f->plane = *plane;
    getAirportsForFlight(f, apm);
    getCorrectDate(&(f->date));
}

int getAirportsForFlight(Flight* f, AirportManager* apm) {
    int doesExist;
    char code[MAX_LENGTH];
    do {
        printf("Enter code of origin airport:     \n");
        myGets(code, MAX_LENGTH);
        doesExist = isAirportCodeInUse(code, apm);
        if (!doesExist) {
            printf("No airport with this code - try again\n");
        }
        else {
            strcpy(f->origin, code);
        }
    } while (!doesExist);

    do {
        printf("Enter code of destination airport:     \n");
        myGets(code, MAX_LENGTH);
        doesExist = isAirportCodeInUse(code, apm);
        if (!doesExist) {
            printf("No airport with this code - try again\n");
        }
        if (isFlightFromSourceAirport(f, code)) {
            printf("Same origin and destination airport\n");
            doesExist = 0;
        }
        else {
            strcpy(f->destination, code);
        }
    } while (!doesExist);
    return 1;
}

int isFlightFromSourceAirport(const Flight* f, char* originCode) {
    return strcmp(f->origin, originCode);
}

int isFlightToDestAirport(const Flight* f, char* destCode) {
    return strcmp(f->destination, destCode);
}

int isPlaneTypeInFlight(const Flight* f, planeType type) {
    return f->plane.type == type;
}

void printFlight(Flight* const f) {
    printf("Flight from %s to %s\n", f->origin, f->destination);
    printDate(&(f->date));
    printPlane(&(f->plane));
}

void freeFlight(Flight* f) { free(f); }

void tempFunction(Flight* f, AirportManager* apm) {
    int inUse, rot = 0;
    char code[MAX_LENGTH];
    do {
        printf("Enter code of %s airport:     \n",
            (rot) ? ("destination") : ("origin"));
        myGets(code, MAX_LENGTH);
        inUse = isAirportCodeInUse(code, apm);
        if (!inUse) {
            printf("No airport with this code - try again\n");
        }
        else if (inUse && !rot) {
            strcpy(f->origin, code);
            rot++;
        }
        else if (inUse && rot) {
            if (isFlightFromSourceAirport(f, code)) {
                printf("Same origin and destination airport\n");
                inUse = 0;
            }
            else {
                strcpy(f->destination, code);
            }
        }
        else {
        }
    } while (!inUse && !rot);
}
