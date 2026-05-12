#include "Cubie.h"


char getU(Cubie* c){return c->faces[0];}
char getR(Cubie* c){return c->faces[1];}
char getF(Cubie* c){return c->faces[2];}
char getL(Cubie* c){return c->faces[3];}
char getB(Cubie* c){return c->faces[4];}
char getD(Cubie* c){return c->faces[5];}

void setU(Cubie* c, char v){c->faces[0] = v;}
void setR(Cubie* c, char v){c->faces[1] = v;}
void setF(Cubie* c, char v){c->faces[2] = v;}
void setL(Cubie* c, char v){c->faces[3] = v;}
void setB(Cubie* c, char v){c->faces[4] = v;}
void setD(Cubie* c, char v){c->faces[5] = v;}

void init_cubbie(Cubie* c, char u, char r, char f, char l, char b, char d){
    c->faces[0] = u;
    c->faces[1] = r;
    c->faces[2] = f;
    c->faces[3] = l; 
    c->faces[4] = b; 
    c->faces[5] = d;
}

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
