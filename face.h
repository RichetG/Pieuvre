#include <string>
#include <vector>
#include "tripletface.h"
using namespace std;

class Face{

public:
    Face();
    void add(TripletFace triplet);
    void remove(TripletFace triplet);
    TripletFace at(int index);
    int size();
    string print();

private:
    vector<TripletFace>listTriplets;
};
