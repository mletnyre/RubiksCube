#ifndef TWOBYTWO_H
#define TWOBYTWO_H

#include "Cubie.h"

typedef struct TwoByTwo{
    Cubie cube[2][2][2];
}TwoByTwo;

TwoByTwo* init_2x2();

void printCube(TwoByTwo* cube);

#endif //TWOBYTWO_H