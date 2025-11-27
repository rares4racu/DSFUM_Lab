#ifndef PIECES_H
#define PIECES_H

#include <Arduino.h>

void pieceLine(byte fb[],int poz1,int poz2);
void pieceLine_rotated(byte fb[],int poz1);
void pieceSquare(byte fb[],int poz1,int poz2);
void pieceLright(byte fb[],int poz1, int poz2);
void pieceLright_rotated1(byte fb[],int poz1, int poz2);
void pieceLright_rotated2(byte fb[],int poz1, int poz2);
void pieceLright_rotated3(byte fb[],int poz1, int poz2);
void pieceLleft(byte fb[],int poz1, int poz2);
void pieceLleft_rotated1(byte fb[],int poz1, int poz2);
void pieceLleft_rotated2(byte fb[],int poz1, int poz2);
void pieceLleft_rotated3(byte fb[],int poz1, int poz2);
void pieceSkewright(byte fb[],int poz1, int poz2);
void pieceSkewright_rotated(byte fb[],int poz1, int poz2);
void pieceSkewleft(byte fb[],int poz1, int poz2);
void pieceSkewleft_rotated(byte fb[],int poz1, int poz2);
void pieceT(byte fb[],int poz1, int poz2);
void pieceT_rotated1(byte fb[],int poz1, int poz2);
void pieceT_rotated2(byte fb[],int poz1, int poz2);
void pieceT_rotated3(byte fb[],int poz1, int poz2);
#endif