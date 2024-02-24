#include "AirportManager.h"

void initManager(AirportManager* apm) {
    apm->theAirports = NULL;
    apm->numOfAirports = 0;

}

int addAirport(AirportManager* apm) {
    Airport* port = (Airport*)malloc(sizeof(Airport));
    if (!port)
        return 0;
    int isCodeInUse;
    do {
        getAirportCode(port->code);
        isCodeInUse = isAirportCodeInUse(port->code, apm);
        if (isCodeInUse)
            printf("This code already in use - enter a different code\n");
    } while (isCodeInUse);
    port = initAirportNoCode(port);
    
    apm->theAirports =
        (Airport**)realloc(apm->theAirports, (apm->numOfAirports +1) * sizeof(Airport*));
    if (!apm->theAirports)
        return 0;
    apm->theAirports[apm->numOfAirports] = port;
    apm->numOfAirports++;
    return 1;
}

int isAirportCodeInUse(char* code, const AirportManager* apm) {
    for (int i = 0; i < apm->numOfAirports; i++) {
        if (strcmp(apm->theAirports[i]->code, code) == 0) {
            return 1;
        }
    }
    return 0;
}

void printAirports(const AirportManager* apm) {
    printf("there are %d airports\n", apm->numOfAirports);
    for (int i = 0; i < apm->numOfAirports; i++) {
        printAirport(apm->theAirports[i]);
        printf("\n");
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