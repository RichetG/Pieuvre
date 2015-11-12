#include "face.h"
#include <sstream>

Face::Face(){
    listTriplets.clear();
}

void Face::add(TripletFace triplet){
    listTriplets.push_back(triplet);
}

void Face::remove(TripletFace triplet){
    vector<TripletFace>tmp;
    for(int i=0; i<listTriplets.size(); i++){
        if(listTriplets.at(i).print().compare(triplet.print())!=0){
            tmp.push_back(listTriplets.at(i));
        }
        listTriplets.clear();
        listTriplets=tmp;
    }
}

string Face::print(){
    stringstream ligneF;
    string ligne="f ";
    for(int i=0; i<listTriplets.size(); i++){
        ligne+=listTriplets.at(i).print()+" ";
    }
    ligneF<<ligne;
    return ligneF.str();
}
