#include "Flight.h"
#include "GeneralFunctions.h"

void initFlight(Flight* f, Plane* plane, AirportManager* apm) {
    f->plane = *plane;
    getSourceAirport(f, apm);
    getDestAirport(f, apm);
    getCorrectDate(&(f->date));
}

int getSourceAirport(Flight* f, AirportManager* apm) {
    int doesExist;
    char code[MAX_LENGTH];
    do {
        printf("Enter code of origin airport:\n");
        myGets(code, MAX_LENGTH);
        doesExist = isAirportCodeInUse(code, apm);
        if (!doesExist) {
            printf("No airport with this code - try again\n");
        }
        else {
            strcpy(f->origin, code);
        }
    } while (!doesExist);

    return 1;
}

int getDestAirport(Flight* f, AirportManager* apm) {
    int doesExist;
    char code[MAX_LENGTH];
    do {
        printf("Enter code of destination airport:\n");
        myGets(code, MAX_LENGTH);
        doesExist = isAirportCodeInUse(code, apm);
        if (!doesExist) {
            printf("No airport with this code - try again\n");
        }
        else {
            if (!isFlightFromSourceAirport(f, code)) {
                printf("Same origin and destination airport\n");
            }
            else {
                strcpy(f->destination, code);
                return 1;
            }
        }
    } while (!doesExist || !isFlightFromSourceAirport(f, code));
    return 0;
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

void printFlight(const Flight* f) {
    printf("Flight From %s To %s  ", f->origin, f->destination);
    printDate(&(f->date));
    printf("  ");
    printPlane(&(f->plane));
}

void freeFlight(Flight* f)
{ 
    free(f);
}