#ifndef VERTEX
#define VERTEX

#include <string>
#include <vector>
#include <QGLViewer/qglviewer.h>
using namespace std;

class Vertex{

public:
    Vertex(double x, double y, double z);
    double getX();
    double getY();
    double getZ();
    vector<double> getPoids();
    double PoidJoint(int i);
    void setX(double x);
    void setY(double y);
    void setZ(double z);
    void setPoids(vector<double>tabPoids);
    string print();
    qglviewer::Vec convertionVertex();

private:
    double x, y, z;
    vector<double>tabPoids;
};

#endif
