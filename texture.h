#ifndef TEXTURE
#define TEXTURE

#include <string>
using namespace std;

class Texture{

public:
    Texture(double x, double y);
    double getX();
    double getY();
    void setX(double x);
    void setY(double y);
    string print();

private:
    double x, y;
};

#endif
