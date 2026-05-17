#include <stdio.h>
#include <stdlib.h>
#include <raylib.h>
#include <string.h>

#include "Cubie.h"
#include "TwoByTwo.h"

Color getColor(char c){
    switch (c)
    {
    case 'r': return RED;
    case 'o': return ORANGE;
    case 'b': return BLUE;
    case 'g': return GREEN;
    case 'w': return WHITE;
    case 'y': return YELLOW;
    case 'x': return BLACK;
    default: return GRAY;
    }
}

void DrawRubiksCube(TwoByTwo* _2x2){
    Color color;
    Vector3 pos;
    Vector3 upDown = {.9, .1, .9};
    Vector3 leftRight = {.1, .9, .9};
    Vector3 frontBack = {.9, .9, .1};
    int x,y,z;
    for(x = 0; x < 2; x++){
        for(y = 0; y < 2; y++){
            for(z = 0; z < 2; z++){
                for(int side = 0; side < 6; side++){
                    switch (side){
                    case 0:
                        //up face
                        char u = _2x2->cube[z][y][x].faces[0];
                        if(u == 'x') break;
                        Color u_color = getColor(u);
                        pos.x = x; pos.y = y; pos.z = z;
                        DrawCube(pos,.9,1.1,.9,u_color);
                        break;
                    case 1:
                        //right face
                        char r = _2x2->cube[z][y][x].faces[1];
                        if(r == 'x') break;
                        Color r_color = getColor(r);
                        pos.x = x; pos.y = y; pos.z = z;
                        DrawCube(pos,1.1,.9,.9,r_color);
                        break;
                    case 2:
                        //front face
                        char f = _2x2->cube[z][y][x].faces[2];
                        if(f == 'x') break;
                        Color f_color = getColor(f);
                        pos.x = x; pos.y = y; pos.z = z;
                        DrawCube(pos,.9,0.9,1.1,f_color);
                        break;
                    case 3:
                        //left face
                        char l = _2x2->cube[z][y][x].faces[3];
                        if(l == 'x') break;
                        Color l_color = getColor(l);
                        pos.x = x; pos.y = y; pos.z = z;
                        DrawCube(pos, 1.1 ,0.9 ,0.9, l_color);
                        break;
                    case 4:
                        //back face
                        char b = _2x2->cube[z][y][x].faces[4];
                        if(b == 'x') break;
                        Color b_color = getColor(b);
                        pos.x = x; pos.y = y; pos.z = z;
                        DrawCube(pos,0.9,0.9,1.1,b_color);
                        break;
                    case 5:
                        //down face
                        char d = _2x2->cube[z][y][x].faces[5];
                        if(d == 'x') break;
                        Color d_color = getColor(d);
                        pos.x = x; pos.y = y; pos.z = z;
                        DrawCube(pos,.9,1.1,.9,d_color);
                        break;
                    }
                }
                Vector3 c = {x,y,z};
                Vector3 cubeLines = {x,y,z};
                DrawCube(c, 1,1,1, BLACK);
            }
        }
    }
}

int main(int argc, char *argv[]){
    printf("Arg count: %d\n", argc);
    if(argc < 2){
        InitWindow(2500, 1500, "Camera Move");

    Camera3D camera = { 0 };
    camera.position = (Vector3){ 3.0f, 3.0f, 3.0f };
    camera.target   = (Vector3){ 0.0f, 0.0f, 0.0f };
    camera.up       = (Vector3){ 0.0f, 1.0f, 0.0f };
    camera.fovy     = 45.0f;
    camera.projection = CAMERA_ORBITAL;
        //no args, render screen
        InitWindow(800,800,"Test");
        SetTargetFPS(60);
        
        while (!WindowShouldClose())
        {

            BeginDrawing();

            ClearBackground(RAYWHITE);

    while (!WindowShouldClose()){
        TwoByTwo* cube = init_2x2();
        UpdateCamera(&camera, CAMERA_FREE);
            SetTargetFPS(60);
        BeginMode3D(camera);

        DrawRubiksCube(cube);

        EndMode3D();
        EndDrawing();
    }

    CloseWindow();
            EndDrawing();

        }
    }
    else if(argc == 2){
        char* arg = argv[1];
        printf("arg: %c\n", arg);
        if(strcmp(arg, "-d") == 0){
            //development mode
            TwoByTwo* c = init_2x2();
            printCube(c);
            while(1){
                char inp = getchar();
                switch (inp)
                {
                case 'r':
                    R(c);
                    break;
                case 'l':
                    L(c);
                    break;
                case 'f':
                    F(c);
                    break;
                case 'b':
                    B(c);
                    break;
                case 'u':
                    U(c);
                    break;
                case 'd':
                    D(c);
                    break;
                default:
                    break;
                }
            }
        }
    }
    
    printf("Exiting Program\n");
    return 0; 
}