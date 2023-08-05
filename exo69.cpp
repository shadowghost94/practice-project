#include <iostream>
using namespace std;

class vecteur3d
{
    float x, y, z;

public:
    vecteur3d();
    vecteur3d(float, float, float);
};

vecteur3d::vecteur3d()
{
    x=0;
    y=0;
    z=0;
};

vecteur3d::vecteur3d( float c1, float c2, float c3 )
{
    x= c1;
    y= c2;
    z= c3;
}

int main()
{
    return 0;
}
