#include "pieces.h"

// straight tetromino
void pieceLine(byte fb[],int poz1,int poz2)
{
  fb[poz1]=B10000000;
  fb[poz1+4]=B10000000; 
  fb[poz2]=B10000000;
  fb[poz2-4]=B10000000;
}
void pieceLine_rotated(byte fb[],int poz1)
{
  fb[poz1]=B11110000;
}

// Square tetromino
void pieceSquare(byte fb[],int poz1,int poz2)
{
  fb[poz1]=B11000000;
  fb[poz2]=B11000000;
}

// L-tetromino right
void pieceLright(byte fb[],int poz1,int poz2)
{
  fb[poz1]=B10000000;
  fb[poz1+4]=B11000000; 
  fb[poz2]=B10000000;
}
void pieceLright_rotated1(byte fb[],int poz1,int poz2)
{
  fb[poz1]=B11100000; 
  fb[poz2]=B00100000;
}
void pieceLright_rotated2(byte fb[],int poz1,int poz2)
{
  fb[poz1]=B01000000;
  fb[poz1+4]=B01000000; 
  fb[poz2]=B11000000;  
}
void pieceLright_rotated3(byte fb[],int poz1,int poz2)
{
  fb[poz1]=B10000000;
  fb[poz2]=B11100000;
}

// L-tetromino left
void pieceLleft(byte fb[],int poz1,int poz2)
{
  fb[poz1]=B10000000;
  fb[poz1+4]=B10000000; 
  fb[poz2]=B11000000;
}
void pieceLleft_rotated1(byte fb[],int poz1,int poz2)
{
  fb[poz1]=B11100000;
  fb[poz2]=B10000000;
}
void pieceLleft_rotated2(byte fb[],int poz1,int poz2)
{
  fb[poz1]=B01000000;
  fb[poz1+4]=B11000000; 
  fb[poz2]=B01000000;
}
void pieceLleft_rotated3(byte fb[],int poz1,int poz2)
{
  fb[poz1]=B00100000;
  fb[poz2]=B11100000;
}

// Skew tetromino
void pieceSkewright(byte fb[],int poz1,int poz2)
{
  fb[poz1]=B11000000;
  fb[poz1+4]=B10000000; 
  fb[poz2]=B01000000;
}
void pieceSkewright_rotated(byte fb[], int poz1,int poz2)
{
  fb[poz1]=B01100000;
  fb[poz2]=B11000000;
}
void pieceSkewleft(byte fb[], int poz1, int poz2)
{
  fb[poz1]=B11000000;
  fb[poz1+4]=B01000000; 
  fb[poz2]=B10000000;
}
void pieceSkewleft_rotated(byte fb[], int poz1, int poz2)
{
  fb[poz1]=B11000000;
  fb[poz2]=B01100000;
}

// T-tetromino 
void pieceT(byte fb[],int poz1, int poz2)
{
  fb[poz1]=B11000000;
  fb[poz1+4]=B10000000; 
  fb[poz2]=B10000000;
}
void pieceT_rotated1(byte fb[],int poz1, int poz2)
{
  fb[poz1]=B11100000;
  fb[poz2]=B01000000;
}
void pieceT_rotated2(byte fb[], int poz1, int poz2)
{
  fb[poz1]=B11000000;
  fb[poz1+4]=B01000000; 
  fb[poz2]=B01000000;
}
void pieceT_rotated3(byte fb[], int poz1, int poz2)
{
  fb[poz1]=B01000000;
  fb[poz2]=B11100000;
}