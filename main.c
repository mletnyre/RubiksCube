#include <stdio.h>
#include <stdlib.h>
    /*
    cubies are viewed from teh point of view of the person holding the cube,
    holding the cube in the traditional scrambling orientation, white on top and green facing you, red on the right. 
    Assuming we have a traditional color scheme of white opposite yellow, green opposite blue, red opposite oragne.

    With the cube in this oreintation, look at the green, white, red corner. This corner would be
    represented by a cubie by looking at the char array
    [w, r, g, x, x, x]. 
    We start on the top of the cubie, then move to the right face, front face, left face, back face and finally down face.
    Faces that do not appear are marked with x. The bottom, left, back faces of this cubbie are not shown, thus they are 'x'.
    When a move is preformed we must update the cubie. If we apply a U move to the cube this corner will be moved to the back right.
    This mean that the cubie will now be represented with the array
    [w, g, x, x, r, x]; 
    White remains on top, green is now on the right, the front, left and bottom faces are not seen and back is red.

    I have not though through these transformations but I should be able to write these into a function and then pass 
    all the cubies effected by the move.
    */

        /*
    starting front left top corner
    [w, r, g, x, x, x]
    apply U
    [w, g, x, x, r, x]
    apply another U
    [w, x, x, r, g, x]
    apply another U
    [w, x, r, g, x ,x]

    starting front left bottom corner
    [x, r, g, x, x, y] D ->
    [x, g, x, x, r, y] D ->
    [x, x, r, x, g, y]


    //after some scratch paper
    basically what is happening when we apply some move M we can just forget about the faces that run perp to the axis of rotation.
    then we can look at the 4 remaining faces, two pairs of opposites. 
    When we apply the move M what happens is that each pice movse from one pair to the other if its M' or M determines which of those faces it ends up on
    A concrete example would be U move
    so becuase The faces U and B are perp to the axis of rotation we can forget about them,
    then we can look at the current piece
     F   R   B   L 
    [c1, c2, c3, c4] and move them down the line so itbecomes 
    [c4, c1, c2, c3] The way we would applly a U' is to move the other way on the chain
    [c1, c2, c3, c4]
    I think I will define a list like this for each move type so we will have 6 move lists, im not doing slice moves yet.

    ahh just realized that U and D are the same except D is a U'
    Becaue the move is alwyas 90* clockwise relative to the face 
    So L is just R'
    and B is just F'

    U list -> L B R F <- D list
    R list -> F U B D <- L list
    F list -> U R D L<- B list

    //there's most def a way to make this even more abstract but I dont care about that right now.

    //

    There should be some way to ambiguously define a 90* turn because it doesnt matter wht orientation the cube is in. Basically
    You could solve the cube by only doing R's if you just turned the whole cube before turning, idk if that makes sense.


    just noting my thoughts here, I see that white obviously stays on the top the whole time and the bottom face is never shown.
    This will hold for whatever move we do so if we do an R then the right face will never change and the left face will never show.
    We can tell what piece this is by what isnt showing. 
    [c, c, c, x, x, x] - ftr (front top right, c = color)
    [c, c, x, x, c, x] - btr
    [c, x, x, c, c, x] - btl
    [c, x, c, c, x, x] - ftl

    another thing, we can distinguish corners from edges (for when we do 3x3) by looking at howmany colors there are 2 = edge 3 = corner, 1 = middle 
    piece if I get brave enough for 4x4.

    */

typedef struct Cubie{
    char faces[6];
}Cubie;

typedef struct TwoByTwo{
    Cubie cube[2][2][2];
}TwoByTwo;

void init_cubbie(Cubie* c, char u, char r, char f, char l, char b, char d){
    c->faces[0] = u;
    c->faces[1] = r;
    c->faces[2] = f;
    c->faces[3] = l; 
    c->faces[4] = b; 
    c->faces[5] = d;
}

char getU(Cubie* c){return c->faces[0];}
char getR(Cubie* c){return c->faces[1];}
char getF(Cubie* c){return c->faces[2];}
char getL(Cubie* c){return c->faces[3];}
char getB(Cubie* c){return c->faces[4];}
char getD(Cubie* c){return c->faces[5];}

char setU(Cubie* c, char v){c->faces[0] = v;}
char setR(Cubie* c, char v){c->faces[1] = v;}
char setF(Cubie* c, char v){c->faces[2] = v;}
char setL(Cubie* c, char v){c->faces[3] = v;}
char setB(Cubie* c, char v){c->faces[4] = v;}
char setD(Cubie* c, char v){c->faces[5] = v;}

void U_Dp(Cubie* c){
    //grab the L B R F elements from this cubie
    char L, B, R, F, nL, nB, nR, nF;
    L = getL(c);
    B = getB(c);
    R = getR(c);
    F = getF(c);

    nL = F;
    nB = L;
    nR = B;
    nF = R;

    setL(c, nL);
    setB(c, nB);
    setR(c, nR);
    setF(c, nF);
}

void D_Up(Cubie* c){
    //grab the L B R F elements from this cubie
    char L, B, R, F, nL, nB, nR, nF;
    L = getL(c);
    B = getB(c);
    R = getR(c);
    F = getF(c);

    nL = B;
    nB = R;
    nR = F;
    nF = L;

    setL(c,nL);
    setB(c,nB);
    setR(c,nR);
    setF(c,nF);
}

void L_Rp(Cubie* c){
    char U, B, D, F, nU, nB, nD, nF;
    U = getU(c);
    B = getB(c);
    D = getD(c);
    F = getF(c);

    nU = B;
    nB = D;
    nD = F;
    nF = U;

    setU(c, nU);
    setB(c, nB);
    setD(c, nD);
    setF(c, nF);
}

void R_Lp(Cubie* c){
    L_Rp(c);
    L_Rp(c);
    L_Rp(c);
}


void F_Bp(Cubie* c){
    char U, R, D, L, nU, nR, nD, nL;
    U = getU(c);
    R = getR(c);
    D = getD(c);
    L = getL(c);

    nU = L;
    nL = D;
    nD = R;
    nR = U;
    
    setU(c, nU);
    setL(c, nL);
    setR(c, nR);
    setD(c, nD);
}

//someting a little silly
void B_Fp(Cubie* c){
    F_Bp(c);
    F_Bp(c);
    F_Bp(c);
}

void printCube(TwoByTwo* cube){
    printf("Printing Cube\n");
    int x, y, z;
    for(z = 0; z < 2; z++){
        for(y = 0; y < 2; y++){
            for(x = 0; x < 2; x++){
                printf("Cubie at locatoin (%d,%d,%d) looks like %c, %c, %c, %c, %c, %c\n",
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
                else if(y == 1){
                    setL(c, 'x');
                    setR(c, 'r');
                }
                if(z == 0){
                    setF(c, 'b');
                    setB(c, 'x');
                }
                else if(y == 1){
                    setF(c, 'x');
                    setB(c, 'g');
                }
                cube->cube[z][y][x] = *c;
            }
        }
    }
    printf("Printing Cube before Return\n");
    printCube(cube);
}

int main(){
    TwoByTwo* c = init_2x2();
    printCube(c);

    printf("Exiting Program\n");
}