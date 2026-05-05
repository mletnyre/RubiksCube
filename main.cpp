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
    Cubie(){}

    private:
    char faces[6];
}

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