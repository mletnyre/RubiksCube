#include "RubiksCube.h"

#include <stdlib.h>
#include <stdio.h>

#define UP 5
#define RIGHT 1
#define FRONT 2
#define LEFT 3
#define BACK 4
#define DOWN 0



void printCube(RubiksCube* cube){
    printf("Printing Cube\n");
    int x, y, z;
    int size = cube->size;
    for(z = 0; z < size; z++){
        for(y = 0; y < size; y++){
            for(x = 0; x < size; x++){
                printf("Cubie at location (%d,%d,%d) looks like %c, %c, %c, %c, %c, %c\n",
                x, y, z, 
                cube->cube[z][y][x].faces[UP],
                cube->cube[z][y][x].faces[RIGHT],
                cube->cube[z][y][x].faces[FRONT],
                cube->cube[z][y][x].faces[LEFT],
                cube->cube[z][y][x].faces[BACK],
                cube->cube[z][y][x].faces[DOWN]);
            }
        }
    }
}

RubiksCube* init_nxn(int size){
    int x, y, z;
    RubiksCube *cube;
    printf("Making Rubik's cube of size n = %d\n", size);
    cube->cube = malloc(size * sizeof(Cubie**));
    for(z = 0; z < size; z++){
        cube->cube[z] = malloc(size * sizeof(int *));
        for(y = 0; y < size; y++){
            cube->cube[z][y] = malloc(size * sizeof(Cubie));
         }
    }
    cube->size = size;
    for(z = 0; z < size; z++){
        for(y = 0; y < size; y++){
            for(x = 0; x < size; x++){
                printf("Initalizing cubie at location (%d,%d,%d)\n", x, y, z);
                /*
                if y is 0 then the u face is white
                if y is 1 the d face is yellow
                if x is 0 the l face is orange
                if x is 1 the r face is red
                if z is 0 the b face is blue
                if z is 1 the f face is green
                */
                Cubie *c = malloc(sizeof(Cubie));
                if(y == 0){
                    setU(c, 'y');
                    setD(c, 'x');
                }
                else if(y == size-1){
                    setU(c, 'x');
                    setD(c, 'w');
                }
                else{
                    setU(c, 'x');
                    setD(c, 'x'); 
                }
                if(x == 0){
                    setL(c, 'o');
                    setR(c, 'x');
                }
                else if(x == size-1){
                    setL(c, 'x');
                    setR(c, 'r');
                }
                else{
                    setL(c, 'x');
                    setR(c, 'x'); 
                }
                if(z == 0){
                    setB(c, 'b');
                    setF(c, 'x');
                }
                else if(z == size-1){
                    setB(c, 'x');
                    setF(c, 'g');
                }
                else{
                    setB(c, 'x');
                    setF(c, 'x');
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
                Layer[i]->faces[UP],
                Layer[i]->faces[RIGHT],
                Layer[i]->faces[FRONT],
                Layer[i]->faces[LEFT],
                Layer[i]->faces[BACK],
                Layer[i]->faces[DOWN]);

            }
}

void getULayer(RubiksCube* c, Cubie* layer[4]){
    printf("Getting U Layer\n");
    layer[0] = &c->cube[0][1][0];
    layer[1] = &c->cube[0][1][1];
    layer[2] = &c->cube[1][1][1];
    layer[3] = &c->cube[1][1][0];
    printf("Got U Layer\n");
}

void getDLayer(RubiksCube* c, Cubie* layer[4]){
    layer[0] = &c->cube[0][0][0];
    layer[1] = &c->cube[0][0][1];
    layer[2] = &c->cube[1][0][1];
    layer[3] = &c->cube[1][0][0];
}

void getLLayer(RubiksCube* c, Cubie* layer[4]){
    layer[0] = &c->cube[0][0][0];
    layer[1] = &c->cube[1][0][0];
    layer[2] = &c->cube[1][1][0];
    layer[3] = &c->cube[0][1][0];
}

void getRLayer(RubiksCube* c, Cubie* layer[4]){
    layer[0] = &c->cube[0][0][1];
    layer[1] = &c->cube[1][0][1];
    layer[2] = &c->cube[1][1][1];
    layer[3] = &c->cube[0][1][1];
}

void getFLayer(RubiksCube* c, Cubie* layer[4]){
    layer[0] = &c->cube[1][0][0];
    layer[1] = &c->cube[1][1][0];
    layer[2] = &c->cube[1][1][1];
    layer[3] = &c->cube[1][0][1];
}

void getBLayer(RubiksCube* c, Cubie* layer[4]){
    layer[0] = &c->cube[0][0][0];
    layer[1] = &c->cube[0][1][0];
    layer[2] = &c->cube[0][1][1];
    layer[3] = &c->cube[0][0][1];
}

void RotateCubiesU(RubiksCube* cube){
    //printf("Rotating Cubies U\n");
    Cubie tmp0 = cube->cube[0][1][0];
    Cubie tmp1 = cube->cube[0][1][1];
    Cubie tmp2 = cube->cube[1][1][1];
    Cubie tmp3 = cube->cube[1][1][0];
    
    cube->cube[0][1][0] = tmp3;
    cube->cube[0][1][1] = tmp0;
    cube->cube[1][1][1] = tmp1;
    cube->cube[1][1][0] = tmp2;

    //printf("Done Rotating Cubies U\n");
}

void RotateCubiesD(RubiksCube* cube){
    Cubie tmp0 = cube->cube[0][0][0];
    Cubie tmp1 = cube->cube[0][0][1];
    Cubie tmp2 = cube->cube[1][0][1];
    Cubie tmp3 = cube->cube[1][0][0]; 

    cube->cube[0][0][0] = tmp1;
    cube->cube[0][0][1] = tmp2;
    cube->cube[1][0][1] = tmp3;
    cube->cube[1][0][0] = tmp0;
}

void RotateCubiesL(RubiksCube* cube){
    Cubie tmp0 = cube->cube[0][0][0];
    Cubie tmp1 = cube->cube[1][0][0];
    Cubie tmp2 = cube->cube[1][1][0];
    Cubie tmp3 = cube->cube[0][1][0]; 

    cube->cube[0][0][0] = tmp1;
    cube->cube[1][0][0] = tmp2;
    cube->cube[1][1][0] = tmp3;
    cube->cube[0][1][0] = tmp0;
}

void RotateCubiesR(RubiksCube* cube){
    Cubie tmp0 = cube->cube[0][0][1];
    Cubie tmp1 = cube->cube[1][0][1];
    Cubie tmp2 = cube->cube[1][1][1];
    Cubie tmp3 = cube->cube[0][1][1]; 

    cube->cube[0][0][1] = tmp3;
    cube->cube[1][0][1] = tmp0;
    cube->cube[1][1][1] = tmp1;
    cube->cube[0][1][1] = tmp2;
}

void RotateCubiesF(RubiksCube* cube){
    Cubie tmp0 = cube->cube[1][0][0];
    Cubie tmp1 = cube->cube[1][1][0];
    Cubie tmp2 = cube->cube[1][1][1];
    Cubie tmp3 = cube->cube[1][0][1]; 

    cube->cube[1][0][0] = tmp3;
    cube->cube[1][1][0] = tmp0;
    cube->cube[1][1][1] = tmp1;
    cube->cube[1][0][1] = tmp2; 
}

void RotateCubiesB(RubiksCube* cube){
    Cubie tmp0 = cube->cube[0][0][0];
    Cubie tmp1 = cube->cube[0][1][0];
    Cubie tmp2 = cube->cube[0][1][1];
    Cubie tmp3 = cube->cube[0][0][1]; 

    cube->cube[0][0][0] = tmp1;
    cube->cube[0][1][0] = tmp2;
    cube->cube[0][1][1] = tmp3;
    cube->cube[0][0][1] = tmp0; 
}

void updateSingleCubieU(Cubie* cubie){
    //printf("Cubie in %c %c %c %c\n", cubie->faces[1],cubie->faces[2],cubie->faces[3],cubie->faces[4]);
    char rtmp = cubie->faces[1];
    char ftmp = cubie->faces[2];
    char ltmp = cubie->faces[3];
    char btmp = cubie->faces[4];
    cubie->faces[1] = btmp;
    cubie->faces[2] = rtmp;
    cubie->faces[3] = ftmp;
    cubie->faces[4] = ltmp;
    //printf("Cubie out %c %c %c %c\n", cubie->faces[1],cubie->faces[2],cubie->faces[3],cubie->faces[4]);
}

void updateSingleCubieD(Cubie* cubie){
    //printf("Cubie in %c %c %c %c\n", cubie->faces[1],cubie->faces[2],cubie->faces[3],cubie->faces[4]);
    char rtmp = cubie->faces[1];
    char ftmp = cubie->faces[2];
    char ltmp = cubie->faces[3];
    char btmp = cubie->faces[4];
    cubie->faces[1] = ftmp;
    cubie->faces[2] = ltmp;
    cubie->faces[3] = btmp;
    cubie->faces[4] = rtmp;
    //printf("Cubie out %c %c %c %c\n", cubie->faces[1],cubie->faces[2],cubie->faces[3],cubie->faces[4]);
}
void updateSingleCubieL(Cubie* cubie){
    char dtmp = cubie->faces[0];
    char ftmp = cubie->faces[2];
    char utmp = cubie->faces[5];
    char btmp = cubie->faces[4];
    cubie->faces[0] = ftmp;
    cubie->faces[2] = utmp;
    cubie->faces[5] = btmp;
    cubie->faces[4] = dtmp;
}

void updateSingleCubieR(Cubie* cubie){
    char dtmp = cubie->faces[0];
    char ftmp = cubie->faces[2];
    char utmp = cubie->faces[5];
    char btmp = cubie->faces[4];
    cubie->faces[0] = btmp;
    cubie->faces[2] = dtmp;
    cubie->faces[5] = ftmp;
    cubie->faces[4] = utmp;
}

void updateSingleCubieF(Cubie* cubie){
    char dtmp = cubie->faces[DOWN];
    char rtmp = cubie->faces[RIGHT];
    char ltmp = cubie->faces[LEFT];
    char utmp = cubie->faces[UP];
    cubie->faces[DOWN] = rtmp;
    cubie->faces[RIGHT] = utmp;
    cubie->faces[UP] = ltmp;
    cubie->faces[LEFT] = dtmp;
}

void updateSingleCubieB(Cubie* cubie){
    char dtmp = cubie->faces[0];
    char rtmp = cubie->faces[1];
    char ltmp = cubie->faces[3];
    char utmp = cubie->faces[5];
    cubie->faces[0] = ltmp;
    cubie->faces[1] = dtmp;
    cubie->faces[5] = rtmp;
    cubie->faces[3] = utmp;
}

void UpdateCubies(Cubie* Layer[4], char l){
    //printf("Updating Cubies\n");
    int i;
    for(i = 0; i < 4; i ++){
        if(l == 'U'){updateSingleCubieU(Layer[i]);}
        if(l == 'D'){updateSingleCubieD(Layer[i]);}
        if(l == 'L'){updateSingleCubieL(Layer[i]);}
        if(l == 'R'){updateSingleCubieR(Layer[i]);}
        if(l == 'F'){updateSingleCubieF(Layer[i]);}
        if(l == 'B'){updateSingleCubieB(Layer[i]);}

    }
    //printf("Done updating cubies\n");
}

void U(RubiksCube* c){
    Cubie* ULayer[4];
    getULayer(c, ULayer);
    UpdateCubies(ULayer, 'U');
    RotateCubiesU(c);
}

void D(RubiksCube* c){
    Cubie* DLayer[4];
    getDLayer(c, DLayer);
    UpdateCubies(DLayer, 'D');
    RotateCubiesD(c);
}
void L(RubiksCube* c){
    Cubie* LLayer[4];
    getLLayer(c, LLayer);
    UpdateCubies(LLayer, 'L');
    RotateCubiesL(c);
}
void R(RubiksCube* c){
    Cubie* RLayer[4];
    getRLayer(c,RLayer);
    UpdateCubies(RLayer, 'R');
    RotateCubiesR(c);
}
void F(RubiksCube* c){
    Cubie* FLayer[4];
    getFLayer(c, FLayer);
    UpdateCubies(FLayer, 'F');
    RotateCubiesF(c);
}
void B(RubiksCube* c){
    Cubie* BLayer[4];
    getBLayer(c, BLayer);
    UpdateCubies(BLayer, 'B');
    RotateCubiesB(c);
}