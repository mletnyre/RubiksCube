#include "solver.h"
#include <stdlib.h>

void scramble(RubiksCube* cube){
    int moves = 20;
    int i;
    int m; 
    for(i = 0; i < moves; i ++){
        m = random() % 6;
        switch(m){
            case 0: U(cube);
            case 1: D(cube);
            case 2: R(cube);
            case 3: L(cube);
            case 4: F(cube);
            case 5: B(cube);
        }
    }
}