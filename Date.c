#include "Date.h"
#include <stdio.h>
#include <stdlib.h>

int getCorrectDate(Date* d) {
    int day, month, year;
    do {
        printf("Enter Flight Date dd##mm##yyyy  minimum year 2023\n");
        scanf("%d##%d##%d", &day, &month, &year);
        while (getchar() != '\n');
    } while (checkDate(day, month, year) == 0);

    d->day = day;
    d->month = month;
    d->year = year;

    return 0;
}

int checkDate(int d, int m, int y) {
    int isCorrectDate =
        (m < 1 || m > 12) || (d < 1 || d > monthDays[m - 1]) || (y < 2023);

    if (isCorrectDate) {
        printf("Error try again\n");
        return 0;
    }

    return 1;
}

void printDate(Date* d) {
    printf("Date: %d/%d/%d", d->day, d->month, d->year);
}
