#include <stdio.h>

#include "Cubie.h"
#include "TwoByTwo.h"

void printCubie(Cubie* cubie){
    char r,f,l,b;
    r = cubie->faces[1];
    f = cubie->faces[2];
    l = cubie->faces[3];
    b = cubie->faces[4];
    printf("Cubie: %c,%c,%c,%c\n",r,f,l,b);
}

int main(){
    Cubie* cubie;
    init_cubbie(cubie, 'x','x','x','o','b','w');
    updateSingleCubieU(cubie);
    printCubie(cubie);
    updateSingleCubieU(cubie);
    printCubie(cubie);
    updateSingleCubieU(cubie);
    printCubie(cubie);
    updateSingleCubieU(cubie);
    printCubie(cubie);
    return 0;
}