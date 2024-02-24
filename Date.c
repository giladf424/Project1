#include "Date.h"
#include <stdio.h>
#include "GeneralFunctions.h"
#include <stdlib.h>

int getCorrectDate(Date* d) {
    int day, month, year, check;
    char date[MAX_LENGTH];
    do {
        check = 1;
        printf("Enter Flight Date dd##mm##yyyy  minimum year 2023\n");
        myGets(date, MAX_LENGTH);
        //s = (int)strlen(date);
        sscanf(date, "%d##%d##%d", &day, &month, &year);
        if (date[2] != '#' || date[3] != '#' || date[6] != '#' || date[7] != '#')
        {
            printf("Error try again\n");
            check = 0;
        }
    } while (check == 0 || checkDate(day, month, year) == 0);

    d->day = day;
    d->month = month;
    d->year = year;

    return 0;
}

int checkDate(int d, int m, int y) {
    int isNotCorrectDate =
        (d < 1 || d > monthDays[m - 1])  || (m < 1 || m > 12) || (y < 2023 || y > 9999);

    if (isNotCorrectDate) {
        printf("Error try again\n");
        return 0;
    }

    return 1;
}

void printDate(const Date* d) {
    printf("Date: %02d/%02d/%04d", d->day, d->month, d->year);
}