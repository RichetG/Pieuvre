#ifndef TRIPLETFACE
#define TRIPLETFACE

#include <string>
using namespace std;

class TripletFace{

public:
    TripletFace(int v, int vt, int vn);
    TripletFace(int v, int vt);
    int getV();
    int getVT();
    int getVN();
    void setV(int v);
    void setVT(int vt);
    void setVN(int vn);
    string print();

private:
    double v, vt, vn;
};

#endif
