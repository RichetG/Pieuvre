#ifndef VERTEX
#define VERTEX

#include <string>
#include <vector>
using namespace std;

class Vertex{

public:
    Vertex(double x, double y, double z);
    double getX();
    double getY();
    double getZ();
    vector<double> getPoids();
    void setX(double x);
    void setY(double y);
    void setZ(double z);
    void setPoids(vector<double>tabPoids);
    string print();

private:
    double x, y, z;
    vector<double>tabPoids;
};

#endif
