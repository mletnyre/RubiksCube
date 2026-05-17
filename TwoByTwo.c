#include "TwoByTwo.h"

#include <stdlib.h>
#include <stdio.h>


void printCube(TwoByTwo* cube){
    printf("Printing Cube\n");
    int x, y, z;
    for(z = 0; z < 2; z++){
        for(y = 0; y < 2; y++){
            for(x = 0; x < 2; x++){
                printf("Cubie at location (%d,%d,%d) looks like %c, %c, %c, %c, %c, %c\n",
                x, y, z, 
                cube->cube[z][y][x].faces[0],
                cube->cube[z][y][x].faces[1],
                cube->cube[z][y][x].faces[2],
                cube->cube[z][y][x].faces[3],
                cube->cube[z][y][x].faces[4],
                cube->cube[z][y][x].faces[5]);
            }
        }
    }
}

TwoByTwo* init_2x2(){
    TwoByTwo* cube = malloc(sizeof(TwoByTwo));
    int x, y, z;
    for(z = 0; z < 2; z++){
        for(y = 0; y < 2; y++){
            for(x = 0; x < 2; x++){
                printf("Initalizing cubie at location (%d,%d,%d)\n", x, y, z);
                /*
                if y is 0 then the u face is white
                if y is 1 the d face is yellow
                if x is 0 the l face is orange
                if x is 1 the r face is red
                if z is 0 the b face is blue
                if z is 1 the f face is green
                */
                Cubie* c = malloc(sizeof(Cubie));
                if(y == 0){
                    setU(c, 'w');
                    setD(c, 'x');
                }
                else if(y == 1){
                    setU(c, 'x');
                    setD(c, 'y');
                }
                if(x == 0){
                    setL(c, 'o');
                    setR(c, 'x');
                }
                else if(x == 1){
                    setL(c, 'x');
                    setR(c, 'r');
                }
                if(z == 0){
                    setB(c, 'b');
                    setF(c, 'x');
                }
                else if(z == 1){
                    setB(c, 'x');
                    setF(c, 'g');
                }
                cube->cube[z][y][x] = *c;
            }
        }
    }
    return cube;
}

void PrintLayer(Cubie** Layer){
    for(int i = 0; i < 4; i++){
        printf("Printing out Layer %c, %c, %c, %c, %c, %c\n",
                Layer[i]->faces[0],
                Layer[i]->faces[1],
                Layer[i]->faces[2],
                Layer[i]->faces[3],
                Layer[i]->faces[4],
                Layer[i]->faces[5]);

            }
}

void getULayer(TwoByTwo* c, Cubie layer[4]){
    int x,z;
    for(x = 0; x < 2; x++){
        for(z = 0; z < 2; z++){
                layer[z * 2 + x] = c->cube[z][0][x];
        }
    }
}

void U(TwoByTwo* c){
    Cubie* ULayer;
    getULayer(c, ULayer);
    PrintLayer(&ULayer);
}

void D(TwoByTwo* c){
    
}
void L(TwoByTwo* c){

}
void R(TwoByTwo* c){

}
void F(TwoByTwo* c){

}
void B(TwoByTwo* c){

}