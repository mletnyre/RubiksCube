#ifndef RubiksCube_H
#define RubiksCube_H

#include "Cubie.h"

typedef struct RubiksCube{
    Cubie ***cube;
    int size; //n by n
    char* scramble;
    int scrambleLen;

}RubiksCube;

RubiksCube* init_nxn(int size);

void U(RubiksCube* c);
void D(RubiksCube* c);
void L(RubiksCube* c);
void R(RubiksCube* c);
void F(RubiksCube* c);
void B(RubiksCube* c);
void Uprime(RubiksCube* c);
void Dprime(RubiksCube* c);
void Lprime(RubiksCube* c);
void Rprime(RubiksCube* c);
void Fprime(RubiksCube* c);
void Bprime(RubiksCube* c);

#endif //RubiksCube_H