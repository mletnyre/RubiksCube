#include <stdio.h>
#include <stdlib.h>
#include <raylib.h>
#include <string.h>
#include <unistd.h>

#include "Cubie.h"
#include "RubiksCube.h"

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

void preformMove(int m, int d, RubiksCube* cube){
    switch (m)
    {
    case 0:D(cube);break;
    case 1:L(cube);break;
    case 2:R(cube);break;
    case 3:F(cube);break;
    case 4:B(cube);break;
    case 5:U(cube);break;
    }
    if(d == 1){ preformMove(m, 0, cube);}
}

void Scramble(RubiksCube* cube){
    printf("Scrambling\n");
    int moves = 9; //wca scramble moves
    int m;
    int d;
    for(int i = 0; i < moves; i++){
        printf("Move: %d\n",i);
        m = (rand() % 6);
        d = (rand() % 10);
        preformMove(m, d, cube);
    }
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

    size = nsecs;
    
    RubiksCube* cube  = init_nxn(size);
    printCube(cube);

    
    
    while (!WindowShouldClose()){

        if (IsKeyPressed(KEY_S)){Scramble(cube);}
        if (IsKeyPressed(KEY_U)){U(cube);}
        if (IsKeyPressed(KEY_D)){D(cube);}
        if (IsKeyPressed(KEY_L)){L(cube);}
        if (IsKeyPressed(KEY_R)){R(cube);}
        if (IsKeyPressed(KEY_F)){F(cube);}
        if (IsKeyPressed(KEY_B)){B(cube);}
        if (IsKeyPressed(KEY_Q)){Scramble(cube);}

        BeginDrawing();

        ClearBackground(LIGHTGRAY);
        
        UpdateCamera(&camera, CAMERA_FREE);
        BeginMode3D(camera);

        DrawRubiksCube(cube);
        
        EndMode3D();
        
        EndDrawing();
    }
    
    free(cube);
    CloseWindow();
    return 0;
}