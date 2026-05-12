#include <stdio.h>
#include <stdlib.h>

#include "Cubie.h"
#include "TwoByTwo.h"

int main(){
    TwoByTwo* c = init_2x2();
    printCube(c);

    printf("Exiting Program\n");
}