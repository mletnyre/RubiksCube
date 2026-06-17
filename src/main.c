#include <stdio.h>
#include <stdlib.h>
#include <raylib.h>
#include <string.h>
#include <unistd.h>

#include "Cubie.h"
#include "RubiksCube.h"
#include "solver.h"
#include "main.h"

Color CharToColor(char face){
    switch (face)
    {
    case 'r': return RED;
    case 'o': return ORANGE;
    case 'b': return BLUE;
    case 'g': return GREEN;
    case 'w': return WHITE;
    case 'y': return YELLOW;
    default: return GRAY;
    }
}


int DrawRubiksCube(RubiksCube* Cube){
    int x,y,z,side;
    char face;
    Color faceColor;
    Vector3 pos;
    int size = Cube->size;
    DrawCubeWires((Vector3){x, y, z}, 1, 1, 1, GRAY);
    DrawCube((Vector3){x, y, z}, 1, 1, 1, BLACK);
    for(x=0;x<size;x++){
        for(y=0;y<size;y++){
            for(z=0;z<size;z++){
                Cubie cubie = Cube->cube[z][y][x];
                for(side=0;side<6;side++){
                    pos.x = x; pos.y = y; pos.z = z;
                    face = cubie.faces[side];
                    if(face == 'x') continue;
                    faceColor = CharToColor(face);
                    switch (side)
                    {
                    case 0:
                        pos.y--;
                        DrawCube(pos, .9,.1,.9,faceColor);
                        break;
                    case 1:
                        pos.x++;
                        DrawCube(pos, .1,.9,.9,faceColor);
                        break;
                    case 2:
                        pos.z++;
                        DrawCube(pos, .9,.9,.1,faceColor);
                        break;
                    case 3:
                        pos.x--;
                        DrawCube(pos, .1,.9,.9,faceColor);
                        break;
                    case 4:
                        pos.z--;
                        DrawCube(pos, .9,.9,.1,faceColor);
                        break;
                    case 5:
                        pos.y++;
                        DrawCube(pos, .9,.1,.9,faceColor);
                        break;
                    default:
                        break;
                    }
                }
            }
        }
    }
    return 0;
}

void freeCube(RubiksCube* cube){
    free(cube);
}

RubiksCube* downSizeCube(RubiksCube* cube){
    int size = cube->size;
    if(size == 2){return cube;}
    freeCube(cube);
    return(init_nxn(size-1));
}

RubiksCube* upSizeCube(RubiksCube* cube){
    int size = cube->size;
    if(size == 9){return cube;}
    freeCube(cube);
    return(init_nxn(size+1));
}

int main(int argc, char *argv[]){
    int size;
    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    InitWindow(2000, 1500, "Rubik's Cube");
    SetTargetFPS(60);
    
    Camera3D camera = { 0 };
    camera.position = (Vector3){ 3.0f, 3.0f, 3.0f };
    camera.target   = (Vector3){ 0.0f, 0.0f, 0.0f };
    camera.up       = (Vector3){ 0.0f, 1.0f, 0.0f };
    camera.fovy     = 90.0f;

    //this is largly inspired from the man pages on getopt
    int flags, opt, nsecs, tfind;
    flags, nsecs, tfind = 0; 
    while ((opt = getopt(argc, argv, "n:")) != -1){
        switch(opt){
            case 'n':
            nsecs = atoi(optarg); //optarg is in unistd.h
            tfind = 1;
            break;
        default:
            fprintf(stderr, "Usage %s [-n cubeSize]", argv[0]);
            exit(EXIT_FAILURE);
        }
    }
    
    if(argc == 1){
        size = 2;
    }

    // no cubes smaller than 2x2 or larger than 9x9
    if(nsecs > 9) { size = 9;}
    else if(nsecs < 2) {size = 2;}
    else {size = nsecs;}
    
    RubiksCube* cube  = init_nxn(size);    
    
    while (!WindowShouldClose()){
        size = cube->size;

        //scramble
        if (IsKeyPressed(KEY_Q) && cube->scrambleLen == 0){scramble(cube);}
        if (IsKeyPressed(KEY_Z) && cube->scrambleLen != 0){reverseScramble(cube);}

        //util
        if (IsKeyPressed(KEY_PAGE_UP)) { cube = upSizeCube(cube); }
        if (IsKeyPressed(KEY_PAGE_DOWN)) { cube = downSizeCube(cube); }

        if(IsKeyDown(KEY_ONE) && size >= 4){
            if (IsKeyPressed(KEY_G)){F(cube, 1);}
            if (IsKeyPressed(KEY_T)){U(cube, 1);}
            if (IsKeyPressed(KEY_H)){R(cube, 1);}
            if (IsKeyPressed(KEY_B)){D(cube, 1);}
            if (IsKeyPressed(KEY_F)){L(cube, 1);}
            if (IsKeyPressed(KEY_Y)){B(cube, 1);}
            if (IsKeyPressed(KEY_K)){Fprime(cube, 1);}
            if (IsKeyPressed(KEY_I)){Uprime(cube, 1);}
            if (IsKeyPressed(KEY_L)){Rprime(cube, 1);}
            if (IsKeyPressed(KEY_COMMA)){Dprime(cube, 1);}
            if (IsKeyPressed(KEY_J)){Lprime(cube, 1);}
            if (IsKeyPressed(KEY_O)){Bprime(cube, 1);}
        }
        
        else if(IsKeyDown(KEY_TWO) && size >= 6){
            if (IsKeyPressed(KEY_G)){F(cube, 2);}
            if (IsKeyPressed(KEY_T)){U(cube, 2);}
            if (IsKeyPressed(KEY_H)){R(cube, 2);}
            if (IsKeyPressed(KEY_B)){D(cube, 2);}
            if (IsKeyPressed(KEY_F)){L(cube, 2);}
            if (IsKeyPressed(KEY_Y)){B(cube, 2);}
            if (IsKeyPressed(KEY_K)){Fprime(cube,2 );}
            if (IsKeyPressed(KEY_I)){Uprime(cube,2);}
            if (IsKeyPressed(KEY_L)){Rprime(cube,2);}
            if (IsKeyPressed(KEY_COMMA)){Dprime(cube,2);}
            if (IsKeyPressed(KEY_J)){Lprime(cube,2);}
            if (IsKeyPressed(KEY_O)){Bprime(cube,2);}
        } 
        else if(IsKeyDown(KEY_THREE) && size >= 8){
            if (IsKeyPressed(KEY_G)){F(cube, 3);}
            if (IsKeyPressed(KEY_T)){U(cube,3);}
            if (IsKeyPressed(KEY_H)){R(cube,3);}
            if (IsKeyPressed(KEY_B)){D(cube,3);}
            if (IsKeyPressed(KEY_F)){L(cube,3);}
            if (IsKeyPressed(KEY_Y)){B(cube,3);}
            if (IsKeyPressed(KEY_K)){Fprime(cube, 0);}
            if (IsKeyPressed(KEY_I)){Uprime(cube,3);}
            if (IsKeyPressed(KEY_L)){Rprime(cube,3);}
            if (IsKeyPressed(KEY_COMMA)){Dprime(cube,3);}
            if (IsKeyPressed(KEY_J)){Lprime(cube,3);}
            if (IsKeyPressed(KEY_O)){Bprime(cube,3);}
        }

        //move 
        else if (IsKeyPressed(KEY_G)){F(cube, 0);}
        else if (IsKeyPressed(KEY_T)){U(cube, 0);}
        else if (IsKeyPressed(KEY_H)){R(cube, 0);}
        else if (IsKeyPressed(KEY_B)){D(cube, 0);}
        else if (IsKeyPressed(KEY_F)){L(cube, 0);}
        else if (IsKeyPressed(KEY_Y)){B(cube, 0);}
        else if (IsKeyPressed(KEY_K)){Fprime(cube, 0);}
        else if (IsKeyPressed(KEY_I)){Uprime(cube,0);}
        else if (IsKeyPressed(KEY_L)){Rprime(cube,0);}
        else if (IsKeyPressed(KEY_COMMA)){Dprime(cube,0);}
        else if (IsKeyPressed(KEY_J)){Lprime(cube,0);}
        else if (IsKeyPressed(KEY_O)){Bprime(cube,0);}

        BeginDrawing();

        ClearBackground(LIGHTGRAY);
        
        UpdateCamera(&camera, CAMERA_FREE);
        BeginMode3D(camera);

        DrawRubiksCube(cube);
        
        EndMode3D();
        
        EndDrawing();
    }
    
    //freeCube(cube);
    CloseWindow();
    return 0;
}