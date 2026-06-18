#include "../src/RubiksCube.h"
#include "../src/RubiksCubeInternal.h"

#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>


void printCubie(Cubie* c){
    for(int i = 0; i < 6; i++){
        printf("Printing out Cubie %c, %c, %c, %c, %c, %c\n",
                c->faces[DOWN],
                c->faces[RIGHT],
                c->faces[FRONT],
                c->faces[LEFT],
                c->faces[BACK],
                c->faces[UP]);

            }
}

void test_updateSingleCubieU(){
    Cubie c;
    c.faces[0] = 'y';
    c.faces[1] = 'r';
    c.faces[2] = 'g';
    c.faces[3] = 'o';
    c.faces[4] = 'b';
    c.faces[5] = 'w';
    updateSingleCubieU(&c);
    char testValues[] = {'y', 'b', 'r', 'g', 'o', 'w'};
    for(int i = 0; i < 6; i ++){
        CU_ASSERT_EQUAL(c.faces[i], testValues[i]);
    }
}

void test_updateSingleCubieD(){
    Cubie c;
    c.faces[0] = 'y';
    c.faces[1] = 'r';
    c.faces[2] = 'g';
    c.faces[3] = 'o';
    c.faces[4] = 'b';
    c.faces[5] = 'w';
    updateSingleCubieD(&c);
    char testValues[] = {'y', 'g', 'o', 'b', 'r', 'w'};
    for(int i = 0; i < 6; i ++){
        CU_ASSERT_EQUAL(c.faces[i], testValues[i]);
    }
}

void test_updateSingleCubieF(){
    Cubie c;
    c.faces[0] = 'y';
    c.faces[1] = 'r';
    c.faces[2] = 'g';
    c.faces[3] = 'o';
    c.faces[4] = 'b';
    c.faces[5] = 'w';
    updateSingleCubieF(&c);
    char testValues[] = {'r', 'w', 'g', 'y', 'b', 'o'};
    for(int i = 0; i < 6; i ++){
        CU_ASSERT_EQUAL(c.faces[i], testValues[i]);
    }
}

void test_updateSingleCubieB(){
    Cubie c;
    c.faces[0] = 'y';
    c.faces[1] = 'r';
    c.faces[2] = 'g';
    c.faces[3] = 'o';
    c.faces[4] = 'b';
    c.faces[5] = 'w';
    updateSingleCubieB(&c);
    char testValues[] = {'o', 'y', 'g', 'w', 'b', 'r'};
    for(int i = 0; i < 6; i ++){
        CU_ASSERT_EQUAL(c.faces[i], testValues[i]);
    }
}

void test_updateSingleCubieR(){
    Cubie c;
    c.faces[0] = 'y';
    c.faces[1] = 'r';
    c.faces[2] = 'g';
    c.faces[3] = 'o';
    c.faces[4] = 'b';
    c.faces[5] = 'w';
    updateSingleCubieR(&c);
    char testValues[] = {'b', 'r', 'y', 'o', 'w', 'g'};
    for(int i = 0; i < 6; i ++){
        CU_ASSERT_EQUAL(c.faces[i], testValues[i]);
    }
}

void test_updateSingleCubieL(){
    Cubie c;
    c.faces[0] = 'y';
    c.faces[1] = 'r';
    c.faces[2] = 'g';
    c.faces[3] = 'o';
    c.faces[4] = 'b';
    c.faces[5] = 'w';
    updateSingleCubieL(&c);
    char testValues[] = {'g', 'r', 'w', 'o', 'y', 'b'};
    for(int i = 0; i < 6; i ++){
        CU_ASSERT_EQUAL(c.faces[i], testValues[i]);
    }
}
