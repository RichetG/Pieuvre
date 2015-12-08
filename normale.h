#ifndef NORMALE
#define NORMALE

#include <string>
using namespace std;

class Normale{

public:
    Normale(double x, double y, double z);
    double getX();
    double getY();
    double getZ();
    void setX(double x);
    void setY(double y);
    void setZ(double z);
    string print();

private:
    double x, y, z;
};

#endif
