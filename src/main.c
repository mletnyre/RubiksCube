#include <stdio.h>
#include <stdlib.h>
#include <raylib.h>
#include <string.h>

#include "Cubie.h"
#include "TwoByTwo.h"

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


int DrawRubiksCube(TwoByTwo* Cube){
    int x,y,z,side;
    char face;
    Color faceColor;
    Vector3 pos;
    DrawCubeWires((Vector3){x, y, z}, 1, 1, 1, GRAY);
    DrawCube((Vector3){x, y, z}, 1, 1, 1, BLACK);
    for(x=0;x<2;x++){
        for(y=0;y<2;y++){
            for(z=0;z<2;z++){
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

int main(int argc, char *argv[]){
    printf("Arg count: %d\n", argc);
    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    InitWindow(2000, 1500, "Rubik's Cube");
    SetTargetFPS(60);
    
    Camera3D camera = { 0 };
    camera.position = (Vector3){ 3.0f, 3.0f, 3.0f };
    camera.target   = (Vector3){ 0.0f, 0.0f, 0.0f };
    camera.up       = (Vector3){ 0.0f, 1.0f, 0.0f };
    camera.fovy     = 90.0f;

    TwoByTwo* cube  = init_2x2();
    printCube(cube);

    
    
    while (!WindowShouldClose()){

        if (IsKeyPressed(KEY_U)){
            U(cube);
        }

        BeginDrawing();

        ClearBackground(LIGHTGRAY);
        
        UpdateCamera(&camera, CAMERA_FREE);
        BeginMode3D(camera);

        DrawRubiksCube(cube);

        EndMode3D();

        EndDrawing();
        
    }

    CloseWindow();
    return 0;


    printf("Exiting Program\n");
    return 0; 
}