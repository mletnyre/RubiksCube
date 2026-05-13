#include <stdio.h>
#include <stdlib.h>

#include "Cubie.h"
#include "TwoByTwo.h"

int main(){
    TwoByTwo* c = init_2x2();
    printCube(c);

    char inp = getchar();

    switch (inp)
    {
    case 'r':
        
        break;
    case 'l':
        
        break;
    case 'f':
        
        break;
    case 'b':
        
        break;
    case 'u':
        U(c);
        break;
    case 'd':
        
        break;
    default:
        break;
    }

    printf("Exiting Program\n");
}