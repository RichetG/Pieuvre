#include <string>
using namespace std;

class TripletFace{

public:
    TripletFace(int v, int vt, int vn);
    TripletFace(int v, int vt);
    double getV();
    double getVT();
    double getVN();
    void setV(double v);
    void setVT(double vt);
    void setVN(double vn);
    string print();

private:
    double v, vt, vn;
};
