#include <stdio.h>
#include <stdlib.h>
#include <raylib.h>
#include <string.h>

#include "Cubie.h"
#include "TwoByTwo.h"

int main(int argc, char *argv[]){
    printf("Arg count: %d\n", argc);
    if(argc < 2){
        //no args, render screen
        InitWindow(800,800,"Test");
        SetTargetFPS(60);
        
        while (!WindowShouldClose())
        {

            BeginDrawing();

            ClearBackground(RAYWHITE);

            SetTargetFPS(60);

            DrawText("It works!", 350, 280, 20, BLACK);

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