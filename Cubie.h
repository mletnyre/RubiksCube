#ifndef CUBIE_H
#define CUBIE_H

typedef struct Cubie{
    char faces[6];
}Cubie;

char getU(Cubie* c);
char getR(Cubie* c);
char getF(Cubie* c);
char getL(Cubie* c);
char getB(Cubie* c);
char getD(Cubie* c);

void setU(Cubie* c, char v);
void setR(Cubie* c, char v);
void setF(Cubie* c, char v);
void setL(Cubie* c, char v);
void setB(Cubie* c, char v);
void setD(Cubie* c, char v);

void U_Dp(Cubie* c);
void D_Up(Cubie* c);
void L_Rp(Cubie* c);
void R_Lp(Cubie* c);
void F_Bp(Cubie* c);
void B_Fp(Cubie* c);

void init_cubbie(Cubie* c, char u, char r, char f, char l, char b, char d);

#endif //CUBIE_H