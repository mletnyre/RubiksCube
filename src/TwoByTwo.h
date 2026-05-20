#ifndef TWOBYTWO_H
#define TWOBYTWO_H

#include "Cubie.h"

typedef struct TwoByTwo{
    Cubie cube[2][2][2];
}TwoByTwo;

TwoByTwo* init_2x2();

void printCube(TwoByTwo* cube);

void U(TwoByTwo* c);
void D(TwoByTwo* c);
void L(TwoByTwo* c);
void R(TwoByTwo* c);
void F(TwoByTwo* c);
void B(TwoByTwo* c);

void updateSingleCubieU(Cubie* cubie);

#endif //TWOBYTWO_H