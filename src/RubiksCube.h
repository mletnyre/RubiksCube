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

void U(RubiksCube* c, int in);
void D(RubiksCube* c, int in);
void L(RubiksCube* c, int in);
void R(RubiksCube* c, int in);
void B(RubiksCube* c, int in);
void F(RubiksCube* c, int in);
void Uprime(RubiksCube* c, int in);
void Dprime(RubiksCube* c, int in);
void Lprime(RubiksCube* c, int in);
void Rprime(RubiksCube* c, int in);
void Fprime(RubiksCube* c, int in);
void Bprime(RubiksCube* c, int in);

#endif //RubiksCube_H