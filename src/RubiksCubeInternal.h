#ifndef RUBIKSCUBEINTERNAL_H
#define RUBIKSCUBEINTERNAL_H

#include "../src/RubiksCube.h"

#define UP 5
#define RIGHT 1
#define FRONT 2
#define LEFT 3
#define BACK 4
#define DOWN 0

#include <stdio.h>


void updateSingleCubieU(Cubie* cubie);
void updateSingleCubieD(Cubie* cubie);
void updateSingleCubieF(Cubie* cubie);
void updateSingleCubieB(Cubie* cubie);
void updateSingleCubieR(Cubie* cubie);
void updateSingleCubieL(Cubie* cubie);

void printCubie(Cubie* c);

#endif //RUBIKSCUBEINTERNAL_H