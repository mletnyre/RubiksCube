#include "RubiksCube.h"

#include <stdlib.h>
#include <stdio.h>

#define UP 5
#define RIGHT 1
#define FRONT 2
#define LEFT 3
#define BACK 4
#define DOWN 0

void printLayer(Cubie ** layer, int N) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", layer[i][j].id);
        }
        printf("\n");
    }
}

void printCube(RubiksCube* cube){
    printf("Printing Cube\n");
    int x, y, z;
    int size = cube->size;
    for(z = 0; z < size; z++){
        for(y = 0; y < size; y++){
            for(x = 0; x < size; x++){
                printf("Cubie at location (%d,%d,%d) id: %d looks like %c, %c, %c, %c, %c, %c\n",
                x, y, z, cube->cube[z][y][x].id,
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
    RubiksCube *cube = malloc(sizeof(RubiksCube));
    cube->scrambleLen = 0;
    printf("Making Rubik's cube of size n = %d\n", size);
    cube->cube = malloc(size * sizeof(Cubie**)); 
    for(z = 0; z < size; z++){
        cube->cube[z] = malloc(size * sizeof(int *));
        for(y = 0; y < size; y++){
            cube->cube[z][y] = malloc(size * sizeof(Cubie));
         }
    }
    cube->size = size;
    for(x = 0; x < size; x++){
        for(y = 0; y < size; y++){
            for(z = 0; z < size; z++){
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
                c->id = x + (y * size) + (z * size * size);
                cube->cube[z][y][x] = *c;
            }
        }
    }
    printCube(cube);
    return cube;
}

void printCubie(Cubie** Layer){
    for(int i = 0; i < 6; i++){
        printf("Printing out Cubie %c, %c, %c, %c, %c, %c\n",
                Layer[i]->faces[UP],
                Layer[i]->faces[RIGHT],
                Layer[i]->faces[FRONT],
                Layer[i]->faces[LEFT],
                Layer[i]->faces[BACK],
                Layer[i]->faces[DOWN]);

            }
}

/*
Cubie* layer[4] needs to be a Cubie** layer now becuase we dont know
the size of a layer at compile time

2x2
    layer[0] = &c->cube[0][1][0];
    layer[1] = &c->cube[0][1][1];
    layer[2] = &c->cube[1][1][1];
    layer[3] = &c->cube[1][1][0];

caller needs to free layer
*/
void getULayer(RubiksCube* c, Cubie** layer){
    int x, z, size;
    size = c->size;
    for(x = 0; x < size; x++){
        for(z = 0; z < size; z++){
            layer[x][z] = c->cube[x][size-1][z];
        }
    }
}

// layer[0] = &c->cube[0][0][0];
// layer[1] = &c->cube[0][0][1];
// layer[2] = &c->cube[1][0][1];
// layer[3] = &c->cube[1][0][0];
void getDLayer(RubiksCube* c, Cubie** layer){
    int x, z, size;
    size = c->size;
    for(x = 0; x < size; x++){
        for(z = 0; z < size; z++){
            layer[x][z] = c->cube[x][0][z];
        }
    }
}

// layer[0] = &c->cube[0][0][0];
// layer[1] = &c->cube[1][0][0];
// layer[2] = &c->cube[1][1][0];
// layer[3] = &c->cube[0][1][0];
void getLLayer(RubiksCube* c, Cubie** layer){
    int y, z, size;
    size = c->size;
    for(y = 0; y < size; y++){
        for(z = 0; z < size; z++){
            layer[y][z] = c->cube[y][z][0];
        }
    }
    printLayer(layer, size);
}

// layer[0] = &c->cube[0][0][1];
// layer[1] = &c->cube[1][0][1];
// layer[2] = &c->cube[1][1][1];
// layer[3] = &c->cube[0][1][1];
void getRLayer(RubiksCube* c, Cubie** layer){
    int y, z, size;
    size = c->size;
    for(y = 0; y < size; y++){
        for(z = 0; z < size; z++){
            layer[y][z] = c->cube[y][z][size-1];
        }
    }
}

// layer[0] = &c->cube[1][0][0];
// layer[1] = &c->cube[1][1][0];
// layer[2] = &c->cube[1][1][1];
// layer[3] = &c->cube[1][0][1];
void getFLayer(RubiksCube* c, Cubie** layer){
    int x, y, size;
    size = c->size;
    for(y = 0; y < size; y++){
        for(x = 0; x < size; x++){
            layer[x][y] = c->cube[size-1][x][y];
        }
    }
}

// layer[0] = &c->cube[0][0][0];
// layer[1] = &c->cube[0][1][0];
// layer[2] = &c->cube[0][1][1];
// layer[3] = &c->cube[0][0][1];
void getBLayer(RubiksCube* c, Cubie** layer){
    int x, y, size;
    size = c->size;
    for(y = 0; y < size; y++){
        for(x = 0; x < size; x++){
            layer[y][x] = c->cube[0][y][x];
        }
    }
}

void RotateCubiesU(RubiksCube* cube, Cubie** ULayer){
    int n = cube->size;
    Cubie rotated[n][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            rotated[j][n - 1 - i] = ULayer[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cube->cube[i][n-1][j] = rotated[i][j];
            ULayer[i][j] = rotated[i][j];
        }
    }
}

void RotateCubiesD(RubiksCube* cube, Cubie** layer){
    int n = cube->size;
    Cubie rotated[n][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            //donig this becuase its funny
            rotated[n-1-j][i] = layer[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cube->cube[i][0][j] = rotated[i][j];
            layer[i][j] = rotated[i][j];
        }
    }
}

void RotateCubiesL(RubiksCube* cube, Cubie** layer){
    int n = cube->size;
    Cubie rotated[n][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            //donig this becuase its funny
            rotated[j][n-1-i] = layer[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cube->cube[i][j][0] = rotated[i][j];
            layer[i][j] = rotated[i][j];
        }
    }
}

void RotateCubiesR(RubiksCube* cube, Cubie** layer){
    int n = cube->size;
    Cubie rotated[n][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            //donig this becuase its funny
            rotated[n-1-j][i] = layer[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cube->cube[i][j][n-1] = rotated[i][j];
            layer[i][j] = rotated[i][j];
        }
    }
}

void RotateCubiesF(RubiksCube* cube, Cubie** layer){
    int n = cube->size;
    Cubie rotated[n][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            //donig this becuase its funny
            rotated[n-1-j][i] = layer[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cube->cube[n-1][i][j] = rotated[i][j];
            layer[i][j] = rotated[i][j];
        }
    }
}

void RotateCubiesB(RubiksCube* cube, Cubie** layer){
    int n = cube->size;
    Cubie rotated[n][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            //donig this becuase its funny
            rotated[j][n - 1 - i] = layer[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cube->cube[0][i][j] = rotated[i][j];
            layer[i][j] = rotated[i][j];
        }
    }
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

void UpdateCubies(RubiksCube *c, Cubie** Layer, char l){
    //printf("Updating Cubies\n");
    int x, y, size;
    size = c->size;
    for(x = 0; x < size; x ++){
        for(y = 0; y < size; y++){
            if(l == 'D'){updateSingleCubieD(&Layer[y][x]);}
            if(l == 'L'){updateSingleCubieL(&Layer[y][x]);}
            if(l == 'R'){updateSingleCubieR(&Layer[y][x]);}
            if(l == 'U'){updateSingleCubieU(&Layer[y][x]);}
            if(l == 'F'){updateSingleCubieF(&Layer[y][x]);}
            if(l == 'B'){updateSingleCubieB(&Layer[y][x]);}
        }
    }
    //printf("Done updating cubies\n");
}

Cubie** mallocLayer(int size){
    Cubie ** layer;
    layer = malloc(sizeof(Cubie*)* size);
    for(int i =0 ; i < size; i ++){
        layer[i] = malloc(size*sizeof(Cubie));
    }
    return layer;
}

void freeLayer(Cubie** layer, int size){
    for(int i = 0; i < size; i++){
        free(layer[i]);
    }
    free(layer);
}

void U(RubiksCube* c){
    Cubie ** ULayer = mallocLayer(c->size); 
    getULayer(c, ULayer);
    UpdateCubies(c, ULayer, 'U');
    RotateCubiesU(c, ULayer);
    freeLayer(ULayer, c->size);
}

void D(RubiksCube* c){
    Cubie** DLayer = mallocLayer(c->size); 
    getDLayer(c, DLayer);
    UpdateCubies(c, DLayer, 'D');
    RotateCubiesD(c, DLayer);
    freeLayer(DLayer, c->size);
}
void L(RubiksCube* c){
    Cubie** LLayer = mallocLayer(c->size); 
    getLLayer(c, LLayer);
    UpdateCubies(c, LLayer, 'L');
    RotateCubiesL(c, LLayer);
    freeLayer(LLayer, c->size);
}
void R(RubiksCube* c){
    Cubie** RLayer = mallocLayer(c->size); 
    getRLayer(c,RLayer);
    UpdateCubies(c, RLayer, 'R');
    RotateCubiesR(c,RLayer);
    freeLayer(RLayer, c->size);
}
void F(RubiksCube* c){
    Cubie** FLayer = mallocLayer(c->size); 
    getFLayer(c, FLayer);
    UpdateCubies(c, FLayer, 'F');
    RotateCubiesF(c,FLayer);
    freeLayer(FLayer, c->size);
}
void B(RubiksCube* c){
    Cubie** BLayer = mallocLayer(c->size);  
    getBLayer(c, BLayer);
    UpdateCubies(c, BLayer, 'B');
    RotateCubiesB(c,BLayer);
    freeLayer(BLayer, c->size);
}


void Uprime(RubiksCube* c){
    Cubie ** ULayer = mallocLayer(c->size); 
    getULayer(c, ULayer);
    UpdateCubies(c, ULayer, 'U');
    UpdateCubies(c, ULayer, 'U');
    UpdateCubies(c, ULayer, 'U');
    RotateCubiesU(c, ULayer);
    RotateCubiesU(c, ULayer);
    RotateCubiesU(c, ULayer);
    freeLayer(ULayer, c->size);
}

void Dprime(RubiksCube* c){
    Cubie** DLayer = mallocLayer(c->size); 
    getDLayer(c, DLayer);
    UpdateCubies(c, DLayer, 'D');
    RotateCubiesD(c, DLayer);
    UpdateCubies(c, DLayer, 'D');
    RotateCubiesD(c, DLayer);
    UpdateCubies(c, DLayer, 'D');
    RotateCubiesD(c, DLayer);
    freeLayer(DLayer, c->size);
}
void Lprime(RubiksCube* c){
    Cubie** LLayer = mallocLayer(c->size); 
    getLLayer(c, LLayer);
    UpdateCubies(c, LLayer, 'L');
    RotateCubiesL(c, LLayer);
    UpdateCubies(c, LLayer, 'L');
    RotateCubiesL(c, LLayer);
    UpdateCubies(c, LLayer, 'L');
    RotateCubiesL(c, LLayer);
    freeLayer(LLayer, c->size);
}
void Rprime(RubiksCube* c){
    Cubie** RLayer = mallocLayer(c->size); 
    getRLayer(c,RLayer);
    UpdateCubies(c, RLayer, 'R');
    RotateCubiesR(c,RLayer);
    UpdateCubies(c, RLayer, 'R');
    RotateCubiesR(c,RLayer);
    UpdateCubies(c, RLayer, 'R');
    RotateCubiesR(c,RLayer);
    freeLayer(RLayer, c->size);
}
void Fprime(RubiksCube* c){
    Cubie** FLayer = mallocLayer(c->size); 
    getFLayer(c, FLayer);
    UpdateCubies(c, FLayer, 'F');
    RotateCubiesF(c,FLayer);
    UpdateCubies(c, FLayer, 'F');
    RotateCubiesF(c,FLayer);
    UpdateCubies(c, FLayer, 'F');
    RotateCubiesF(c,FLayer);
    freeLayer(FLayer, c->size);
}
void Bprime(RubiksCube* c){
    Cubie** BLayer = mallocLayer(c->size);  
    getBLayer(c, BLayer);
    UpdateCubies(c, BLayer, 'B');
    RotateCubiesB(c,BLayer);
    UpdateCubies(c, BLayer, 'B');
    RotateCubiesB(c,BLayer);
    UpdateCubies(c, BLayer, 'B');
    RotateCubiesB(c,BLayer);
    freeLayer(BLayer, c->size);
}