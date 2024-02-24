#include <stdio.h>
#include <stdlib.h>
#include "Plane.h"
#include "Airline.h"
#include "AirportManager.h"

int main()
{
	AirportManager apm;
	initManager(&apm);
	Airline airline;
	initAirline(&airline);

	int opt;
	int res;
	do
	{
		printf("Please choose one of the following options\n");
		printf("1 - Add plane\n");
		printf("2 - Add airport\n");
		printf("3 - Add flight\n");
		printf("4 - Print airline details\n");
		printf("5 - Print airport manager details\n");
		printf("6 - Print all existing flights with a specific aircraft type\n");
		printf("7 - Exit\n");
		scanf("%d", &opt);

		switch (opt)
		{
		case 1:
			res = addPlane(&airline);
			if (res)
				printf("The plane has been successfully added\n");
			else
				printf("The plane was not added to the airline\n");
			break;

		case 2:
			res = addAirport(&apm);
			if (res)
				printf("The airport has been successfully added\n");
			else
				printf("The airport was not added\n");
			break;

		case 3:
			res = addFlight(&airline, &apm);
			if (res)
				printf("The flight has been successfully added\n");
			else
				printf("The flight was not added\n");
			break;

		case 4:
			printCompany(&airline);
			break;

		case 5:
			printAirports(&apm);
			break;

		case 6:
			doPrintFlightsWithPlaneType(&airline);
			break;

		case 7:
			freeCompany(&airline);
			freeManager(&apm);
			printf("Bye Bye");
			break;
		}
	} while (opt != 7);
	
}
