#ifndef _TERRAIN_H
#define _TERRAIN_H

class Terrain
{

private :

    int dimx;
    int dimy;
    char ter [100][100];

public :

    Terrain ();

    Terrain(int niveau);

    bool estPositionValide (const int x, const int y) const;


    char getXY (const int x, const int y) const;


    int getDimX () const;


    int getDimY () const;

    int getNumTer() const;

    void setNumTer(int n);

    void ChangeMap(int niveau);

    void setDimX (int x);

    void setDimY (int y);


};

#endif
