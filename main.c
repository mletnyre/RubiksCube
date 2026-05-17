#include <stdio.h>
#include <stdlib.h>
#include <raylib.h>
#include <string.h>

#include "Cubie.h"
#include "TwoByTwo.h"

int main(int argc, char *argv[]){
    printf("Arg count: %d\n", argc);
    if(argc < 2){
        InitWindow(1200, 1000, "Rubik's Cube");
        SetTargetFPS(60);
        
        Camera3D camera = { 0 };
        camera.position = (Vector3){ 3.0f, 3.0f, 3.0f };
        camera.target   = (Vector3){ 0.0f, 0.0f, 0.0f };
        camera.up       = (Vector3){ 0.0f, 1.0f, 0.0f };
        camera.fovy     = 45.0f;

        
        
        while (!WindowShouldClose()){
            ClearBackground(RAYWHITE); // This removes the previous frame
            BeginDrawing();
            UpdateCamera(&camera, CAMERA_FREE);
            BeginMode3D(camera);

            DrawCube((Vector3){0, 0, 0}, 2, 2, 2, RED);
            DrawCubeWires((Vector3){0, 0, 0}, 2, 2, 2, BLACK);

            EndMode3D();

            EndDrawing();
            
        }

        CloseWindow();
        EndDrawing();
        return 0;
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