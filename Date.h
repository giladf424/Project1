#pragma once
#ifndef DATE
#define DATE

static int const monthDays[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

typedef struct {
    int day;
    int month;
    int year;
}Date;

int getCorrectDate(Date* d);

int checkDate(int d, int m, int y);

void printDate(Date* d);


#endif // !DATE
