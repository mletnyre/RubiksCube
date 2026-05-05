#include <iostream>

class Cubie{
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
    public:
    Cubie(char u, char r, char f, char l, char b, char d){
        faces[0] = u;
        faces[1] = r;
        faces[2] = f;
        faces[3] = l; 
        faces[4] = b; 
        faces[5] = d;
    }

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

    private:
    char faces[6];
};

class TwoByTwo{
    public:
    TwoByTwo(){}

    private:
    char cube[2][2][2];
    //        z  y  x
    // index 0 on z is B
    //index 1 on z 
};

int main(){

}