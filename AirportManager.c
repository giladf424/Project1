#include "AirportManager.h"

void initManager(AirportManager* apm) {
    apm->theAirports = NULL;
    apm->numOfAirports = 0;

}

int addAirport(AirportManager* apm) {
    Airport* port = (Airport*)malloc(sizeof(Airport));
    int isCodeInUse;
    do {
        getAirportCode(port->code);
        isCodeInUse = isAirportCodeInUse(port->code, apm);
        if (isCodeInUse)
            printf("This code already in use - enter a different code\n");
    } while (isCodeInUse);
    port = initAirportNoCode(port);
    apm->numOfAirports++;
    apm->theAirports =
        realloc(apm->theAirports, (apm->numOfAirports) * sizeof(Airport*));
    apm->theAirports[apm->numOfAirports - 1] = port;
    apm->theAirports =
        realloc(apm->theAirports, (apm->numOfAirports) * sizeof(Airport*));

    if (!(port))
        return 0;
    return 1;
}

int isAirportCodeInUse(char* code, AirportManager* const apm) {
    for (int i = 0; i < apm->numOfAirports; i++) {
        if (strcmp(apm->theAirports[i]->code, code) == 0) {
            return 1;
        }
    }
    return 0;
}

void printAirports(AirportManager* const apm) {
    printf("there are %d airports\n", apm->numOfAirports);
    for (int i = 0; i < apm->numOfAirports; i++) {
        printAirport(apm->theAirports[i]);
    }
}

void freeManager(AirportManager* apm) {
    for (int i = 0; i < apm->numOfAirports; i++) {
        freeAirport(apm->theAirports[i]);
    }
    free(apm->theAirports);
}

Airport* findAirportByCode(AirportManager* apm, char* code) {
    for (int i = 0; i < apm->numOfAirports; i++) {
        if (strcmp(apm->theAirports[i]->code, code)) {
            return apm->theAirports[i];
        }
    }
    return NULL;
}

