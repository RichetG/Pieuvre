#include <string>
using namespace std;

class Vertex{

public:
    Vertex(double x, double y, double z);
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
