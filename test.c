#include <stdio.h>

#include "Cubie.h"
#include "TwoByTwo.h"

int main(){
    Cubie* cubie;
    init_cubbie(cubie, 'x','r','g','x','x','w');
    updateSingleCubieU(cubie);
    char f,r,l,b;
    r = cubie->faces[1];
    f = cubie->faces[2];
    l = cubie->faces[3];
    b = cubie->faces[4];
    if(r == 'x' && f == 'r' && l == 'g' && b == 'x'){
        printf("SUCCESS!\n");
    }
    else{
        printf("SOMETHING WRONG\n");
    }
    return 0;
}