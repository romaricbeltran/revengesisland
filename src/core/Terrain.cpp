#include "Terrain.h"
#include <cassert>
#include <string>
#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <unistd.h>
#include <stdio.h>


using namespace std;

const char terrain1[18][42] =
{
    "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@",
    "@SSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSV11111@",
    "@SSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSV1111@",
    "@SSSSSSSSSSSSSSSSSSSSSSSSSSSBSSSSSSV111@",
    "@SSSSSSSSSSSSSSSSSSSSSSSSSSSBSSSSSV1111@",
    "@SSSSSSSSSSSSSSSSSSSSSSSSSSSBSSSSV11111@",
    "@SSSSSSSSSSSSSSSSFSSSSSSSSSSSSSSSSV1111@",
    "@SSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSV1111@",
    "@SSSSSSSSSSSSSSSSSSSSBSSSSSSSSSSSV11111@",
    "@SSSSSSSSSSSSSSSSFSSSBSSSSSSSSSSSSV1111@",
    "@SSSSSSSSSSSSSSSSSSSSBSSSSSSSSSSSSV1111@",
    "@SSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSV11111@",
    "@SSSSSSSSSSSSSSSSFSSSSSSSSSSSSSSSSV1111@",
    "@SSSSSSSSSSSSSSSSSSSSSSSSSSSBSSSSSV1111@",
    "@SSSSSSSSSSSSSSSSSSSSSSSSSSSBSSSSSSV111@",
    "@SSSSSSSSSSSSSSSSSSSSSSSSSSSBSSSSSV1111@",
    "@SSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSV11111@",
    "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@"
};

const char terrain2[18][42] =
{
    "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@",
    "@HAHHHHAHHHHAHHHHAHHHHAHHHHAHHHHAHHHHAH@",
    "@HHHHFHHHHFHHHHFHHHHFHHHHFHHHHFHHHHFHHH@",
    "@HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH@",
    "@HHHHAHHHHAHHHHAHHHHAHHHHAHHHHAHHHHAHHH@",
    "@HAHHHHAHHHHAHHHHAHHHHAHHHHAHHHHAHHHHAH@",
    "@HHHHFHHHHFHHHHFHHHHFHHHHFHHHHFHHHHFHHH@",
    "@HFHHHHFHHHHFHHHHFHHHHFHHHHFHHHHFHHHHFH@",
    "@HHHHAHHHHAHHHHAHHHHAHHHHAHHHHAHHHHAHHH@",
    "@HAHHHHAHHHHAHHHHAHHHHAHHHHAHHHHAHHHHAH@",
    "@HHHHFHHHHFHHHHFHHHHFHHHHFHHHHFHHHHFHHH@",
    "@HFHHHHFHHHHFHHHHFHHHHFHHHHFHHHHFHHHHFH@",
    "@HHHHAHHHHAHHHHAHHHHAHHHHAHHHHAHHHHAHHH@",
    "@HAHHHHAHHHHAHHHHAHHHHAHHHHAHHHHAHHHHAH@",
    "@HHHHFHHHHFHHHHFHHHHFHHHHFHHHHFHHHHFHHH@",
    "@HFHHHHFHHHHFHHHHFHHHHFHHHHFHHHHFHHHHFH@",
    "@HHHHAHHHHAHHHHAHHHHAHHHHAHHHHAHHHHAHHH@",
    "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@"
};

const char terrain3[18][42] =
{
    "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@",
    "@PPPPPPPPRPPFPPPPPPFPPPPPPFPPPPPPFPPPPP@",
    "@PPPPPPPPRPPFPPPPPPFPPPPPPFPPPPPPFPPPPP@",
    "@PPPPPPPPRPPFPPPPPPFPPPPPPFPPPPPPFPPPPP@",
    "@PPPPPPPPRPPFPPPPPPFPPPPPPFPPPPPPFPPPPP@",
    "@PPPPPPPPRPPFPPPPPPFPPPPPPFPPPPPPFPPPPP@",
    "@RRRRRRPRRPPFPPPPPPFPPPPPPFPPPPPPFPPPPP@",
    "@PPPPPPPPPPPFPPPPPPFPPPPPPFPPPPPPFPPPPP@",
    "@DDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDD@",
    "@DDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDD@",
    "@PPPPPPPPPPPFPPPPPPFPPPPPPFPPPPPPFPPPPP@",
    "@RRRRRRPRRPPFPPPPPPFPPPPPPFPPPPPPFPPPPP@",
    "@PPPPPPPPRPPFPPPPPPFPPPPPPFPPPPPPFPPPPP@",
    "@PPPPPPPPRPPFPPPPPPFPPPPPPFPPPPPPFPPPPP@",
    "@PPPPPPPPRPPFPPPPPPFPPPPPPFPPPPPPFPPPPP@",
    "@PPPPPPPPRPPFPPPPPPFPPPPPPFPPPPPPFPPPPP@",
    "@PPPPPPPPRPPFPPPPPPFPPPPPPFPPPPPPFPPPPP@",
    "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@"
};

const char terrain4[18][42] =
{
    "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@",
    "@cccccccccccccccccccccccccccccccccccccc@",
    "@cccccccccccccccccccccccccccccccccccccc@",
    "@cccccccccccccccccccccccccccccccccccccc@",
    "@dddddddddddd<ccccccccccccccccccccccccc@",
    "@ppppppppppppwccccccccccccccccccccccccc@",
    "@ppppppppppppwccccccccccccccccccccccccc@",
    "@ppppppppppppwccccccccccccccccccccccccc@",
    "@TTTTTTTTTTTTtTTTTTTTTTTTTTTTTTTTTTTTTT@",
    "@TTTTTTTTTTTTtTTTTTTTTTTTTTTTTTTTTTTTTT@",
    "@ppppppppppppwccccccccccccccccccccccccc@",
    "@ppppppppppppwccccccccccccccccccccccccc@",
    "@ppppppppppppwccccccccccccccccccccccccc@",
    "@mmmmmmmmmmmm>ccccccccccccccccccccccccc@",
    "@cccccccccccccccccccccccccccccccccccccc@",
    "@cccccccccccccccccccccccccccccccccccccc@",
    "@cccccccccccccccccccccccccccccccccccccc@",
    "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@"
};

Terrain::Terrain ()
{
    dimx = 40;
    dimy = 18;
    for(int x=0; x<dimx; ++x)
        for(int y=0; y<dimy; ++y)
                ter[x][y] = terrain1[dimy-1-y][x];
}

bool Terrain::estPositionValide (const int x, const int y) const
{
    return ((x>=0) && (x<dimx) &&
            (y>=0) && (y<dimy) &&
            (ter[x][y]!='@') && (ter[x][y]!='R') &&
            (ter[x][y]!='A') && (ter[x][y]!='B') &&
            (ter[x][y]!='V') && (ter[x][y]!='F'));
}


char Terrain::getXY (const int x, const int y) const
{
    assert(x>=0);
    assert(y>=0);
    assert(x<dimx);
    assert(y<dimy);
    return ter[x][y];
}

int Terrain::getDimX () const
{
    return dimx;
}

int Terrain::getDimY () const
{
    return dimy;
}

void Terrain::setDimX(int x)
{
    dimx=x;
}

void Terrain::setDimY(int y)
{
    dimy=y;
}
void Terrain::ChangeMap (int niveau)
{
    dimx = 40;
    dimy = 18;
    for(int x=0; x<dimx; ++x)
        for(int y=0; y<dimy; ++y)
            switch(niveau)
            {
            case 1 :
                ter[x][y] = terrain1[dimy-1-y][x];
                break;
            case 2 :
                ter[x][y] = terrain2[dimy-1-y][x];
                break;
            case 3 :
                ter[x][y] = terrain3[dimy-1-y][x];
                break;
            case 4 :
                ter[x][y] = terrain4[dimy-1-y][x];
                break;
            }
}
