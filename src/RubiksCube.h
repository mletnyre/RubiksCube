#ifndef RubiksCube_H
#define RubiksCube_H

#include "Cubie.h"

typedef struct RubiksCube{
    Cubie ***cube;
    int size; //n by n
}RubiksCube;

RubiksCube* init_nxn(int size);

void printCube(RubiksCube* cube);

void U(RubiksCube* c);
void D(RubiksCube* c);
void L(RubiksCube* c);
void R(RubiksCube* c);
void F(RubiksCube* c);
void B(RubiksCube* c);

void updateSingleCubieU(Cubie* cubie);

#endif //RubiksCube_H