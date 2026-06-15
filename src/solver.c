#include "solver.h"
#include <stdlib.h>

#include <stdio.h>
#include <stdlib.h>


/*
the cube should be able to remember the scramble, maybe every move applied
to it and then it can reverse the moves to sovle itself.
We should also be able to press some button and have the scrambel print out into 
the console.
*/

typedef enum{
    _2X2 = 9,
    _3x3 = 20,
    _4x4 = 40,
    _5x5 = 60,
    _6x6 = 80,
    _7x7 = 100

}CubeScrambleLen;

int regulationCubesMoveLength(int size){
    switch(size){
        case 1: return 0;
        case 2: return _2X2;
        case 3: return _3x3;
        case 4: return _4x4;
        case 5: return _5x5;
        case 6: return _6x6; 
        case 7: return _7x7;
        default: return (size * size)*2;
    }
}

//this function is gross i know
void scramble(RubiksCube* cube){
    int m, i, moves, size;

    size = cube->size;

    if(size < 8){moves = regulationCubesMoveLength(size);}

    cube->scramble = malloc(sizeof(char)*moves*3);
    int prime, twice;

    for(i = 0; i < moves; i ++){
        m = random() % 18;
        printf("%d\n", m);
        switch(m){
            case 0:     
                U(cube);
                cube->scramble[i] = 'U';
                break;
            case 1: 
                D(cube);
                cube->scramble[i] = 'D';
                break;
            case 2: 
                R(cube);
                cube->scramble[i] = 'R';
                break;
            case 3: 
                L(cube);
                cube->scramble[i] = 'L';
                break;
            case 4: 
                F(cube);
                cube->scramble[i] = 'F';
                break;
            case 5: 
                B(cube);
                cube->scramble[i] = 'B';
                break;
            case 6:     
                U(cube);
                cube->scramble[i] = 'U';
                prime = 1;
                break;
            case 7: 
                D(cube);
                cube->scramble[i] = 'D';
                prime = 1;
                break;
            case 8: 
                R(cube);
                cube->scramble[i] = 'R';
                prime = 1;
                break;
            case 9: 
                L(cube);
                cube->scramble[i] = 'L';
                prime = 1;
                break;
            case 10: 
                F(cube);
                cube->scramble[i] = 'F';
                prime = 1;
                break;
            case 11: 
                B(cube);
                cube->scramble[i] = 'B';
                prime = 1;
                break;
            case 12:     
                U(cube);
                cube->scramble[i] = 'U';
                twice = 1;
                break;
            case 13: 
                D(cube);
                cube->scramble[i] = 'D';
                twice = 1;
                break;
            case 14: 
                R(cube);
                cube->scramble[i] = 'R';
                twice = 1;
                break;
            case 15: 
                L(cube);
                cube->scramble[i] = 'L';
                twice = 1;
                break;
            case 16: 
                F(cube);
                cube->scramble[i] = 'F';
                twice = 1;
                break;
            case 17: 
                B(cube);
                cube->scramble[i] = 'B';
                twice = 1;
                break;
        }
        
        if(prime == 1){
            i++;
            moves++;
            cube->scramble[i] = '\'';
            prime = 0;
        }
        if(twice == 1){
            i++;
            moves++;
            cube->scramble[i] = '2';
            twice = 0;
        }
        
        i++;
        moves++;
        cube->scramble[i] = ' ';
    }
    cube->scramble[moves] = '\0';
    printf("Scramble %s\n", cube->scramble);
}