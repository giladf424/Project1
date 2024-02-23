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
	printf("Please choose one of the following options\n");
	printf("1 - Add plane\n");
	printf("2 - Add airport\n");
	printf("3 - Add flight\n");
	printf("4 - Print airline details\n");
	printf("5 - Print airport manager details\n");
	printf("6 - Print all existing flights with a specific aircraft type\n");
	printf("7 - Exit\n");
	scanf("%d", &opt);
	getchar();
	

	
	switch (opt)
	{
	case 1:
		
		break;

	case 2:
		
		break;

	case 3:
		
		break;

	case 4:
		
		break;

	case 5:
		
		break;

	case 6:

		break;

	case 7:

		break;
	}
}
