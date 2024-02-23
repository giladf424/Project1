#include "Plane.h"

void initPlane(Plane* p, Plane* planeArr, int s) {
    p->serialNum = getPlaneSN(planeArr, s);
    printf("\n");
    p->type = getPlaneType();
    printf("\n");
}

int getPlaneSN(Plane* planeArr, int s) {
    int sn, i = 0;
    do {
        printf("Enter plane serial number - between %d to %d\n", 1, 9999);
        scanf("%d", &sn);
        if (sn > 0 && sn <= 9999)
            i = isSerialNumUnique(planeArr, sn, s);
    } while (i == 0);
    return sn;
}

int isSerialNumUnique(Plane* planeArr, int sn, int s) {
    for (int i = 0; i < s; i++) {
        if (planeArr[i].serialNum == sn)
            printf("There is already a plane with the number you selected, please choose another number.");
            return 0;
    }
    return 1;
}

planeType getPlaneType() {
    int type;
    do {
        printf("\nPlease enter one of the following types\n");
        for (int i = 0; i < noOfType; i++) {
            printf("%d for %s\n", i, planeTypeStr[i]);
        }

        scanf("%d", &type);
        if (type < 0 || type > 2)
            printf("Wrong number , please try again.");
    } while (type < 0 || type > 2);
    return type;
}

void printPlane(const Plane* p) {
    printf("Plane: serial number:%d, type %s", p->serialNum, planeTypeStr[p->type]);
}