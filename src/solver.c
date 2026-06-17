#include "solver.h"
#include <stdlib.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h> //this may not work on windows? its late idk 


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
    int in =0;
    for(i = 0; i < moves; i ++){
        m = random() % 18;
        printf("%d\n", m);
        switch(m){
            case 0:     
                U(cube, in);
                cube->scramble[i] = 'U';
                break;
            case 1: 
                D(cube, in);
                cube->scramble[i] = 'D';
                break;
            case 2: 
                R(cube, in );
                cube->scramble[i] = 'R';
                break;
            case 3: 
                L(cube, in);
                cube->scramble[i] = 'L';
                break;
            case 4: 
                F(cube, in);
                cube->scramble[i] = 'F';
                break;
            case 5: 
                B(cube, in);
                cube->scramble[i] = 'B';
                break;
            case 6:     
                Uprime(cube, in);
                cube->scramble[i] = 'U';
                prime = 1;
                break;
            case 7: 
                Dprime(cube, in);
                cube->scramble[i] = 'D';
                prime = 1;
                break;
            case 8: 
                Rprime(cube, in );
                cube->scramble[i] = 'R';
                prime = 1;
                break;
            case 9: 
                Lprime(cube, in);
                cube->scramble[i] = 'L';
                prime = 1;
                break;
            case 10: 
                Fprime(cube, in);
                cube->scramble[i] = 'F';
                prime = 1;
                break;
            case 11: 
                Bprime(cube, in);
                cube->scramble[i] = 'B';
                prime = 1;
                break;
            case 12:     
                U(cube, in);
                U(cube, in);
                cube->scramble[i] = 'U';
                twice = 1;
                break;
            case 13: 
                D(cube, in);
                D(cube, in);
                cube->scramble[i] = 'D';
                twice = 1;
                break;
            case 14: 
                R(cube, in);
                R(cube, in);
                cube->scramble[i] = 'R';
                twice = 1;
                break;
            case 15: 
                L(cube, in );
                L(cube, in );
                cube->scramble[i] = 'L';
                twice = 1;
                break;
            case 16: 
                F(cube, in);
                F(cube, in);
                cube->scramble[i] = 'F';
                twice = 1;
                break;
            case 17: 
                B(cube, in);
                B(cube, in);
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
    cube->scrambleLen = moves;
}


void processMove(RubiksCube* cube, char* move){
    int in = 0;
         if(strcmp(move, "U")  == 0){ printf("processing a move rn frfr \n"); Uprime(cube, in);}
    else if(strcmp(move, "D")  == 0){ printf("processing a move rn frfr \n"); Dprime(cube, in);}
    else if(strcmp(move, "R")  == 0){ printf("processing a move rn frfr \n"); Rprime(cube, in);}
    else if(strcmp(move, "L")  == 0){ printf("processing a move rn frfr \n"); Lprime(cube, in);}
    else if(strcmp(move, "B")  == 0){ printf("processing a move rn frfr \n"); Bprime(cube, in);}
    else if(strcmp(move, "F")  == 0){ printf("processing a move rn frfr \n"); Fprime(cube, 0);}
    else if(strcmp(move, "U'") == 0){ printf("processing a move rn frfr \n"); U(cube, in);}
    else if(strcmp(move, "D'") == 0){ printf("processing a move rn frfr \n"); D(cube, in);}
    else if(strcmp(move, "R'") == 0){ printf("processing a move rn frfr \n"); R(cube, in);}
    else if(strcmp(move, "L'") == 0){ printf("processing a move rn frfr \n"); L(cube, in);}
    else if(strcmp(move, "B'") == 0){ printf("processing a move rn frfr \n"); B(cube, in);}
    else if(strcmp(move, "F'") == 0){ printf("processing a move rn frfr \n"); F(cube, 0);}
    else if(strcmp(move, "U2") == 0){ printf("processing a move rn frfr \n"); U(cube, in); U(cube, in);}
    else if(strcmp(move, "D2") == 0){ printf("processing a move rn frfr \n"); D(cube, in); D(cube, in);}
    else if(strcmp(move, "R2") == 0){ printf("processing a move rn frfr \n"); R(cube, in); R(cube, in);}
    else if(strcmp(move, "L2") == 0){ printf("processing a move rn frfr \n"); L(cube, in); L(cube, in);}
    else if(strcmp(move, "B2") == 0){ printf("processing a move rn frfr \n"); B(cube, in); B(cube, in);}
    else if(strcmp(move, "F2") == 0){ printf("processing a move rn frfr \n"); F(cube, 0); F(cube, 0);}
}

void reverseScramble(RubiksCube* cube){
    char* scramble = cube->scramble;
    int i;
    char v;
    char move[3];
    for(i = cube->scrambleLen-1; i >= 0; i--){
        v = scramble[i];
        if(v == ' ') continue;

        if(v == '\'' || v == '2'){
            move[1] = v;
            move[0] = scramble[i-1];
            move[2] = '\0';
            i--;
        }
        else{
            move[0] = v;
            move[1] = '\0';
        }
        processMove(cube, move);
        printf("Processing Move: %s\n", move);
    }
    free(cube->scramble);
    cube->scrambleLen = 0;
}