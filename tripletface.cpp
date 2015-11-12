#include "tripletface.h"
#include <sstream>

TripletFace::TripletFace(int v, int vt, int vn){
    this->v=v;
    this->vt=vt;
    this->vn=vn;
}

TripletFace::TripletFace(int v, int vt){
    this->v=v;
    this->vt=vt;
    vn=-1;
}

double TripletFace::getV(){
    return v;
}

double TripletFace::getVT(){
    return vt;
}

double TripletFace::getVN(){
    return vn;
}

void TripletFace::setV(double v){
    this->v=v;
}

void TripletFace::setVT(double vt){
    this->vt=vt;
}

void TripletFace::setVN(double vn){
    this->vn=vn;
}

string TripletFace::print(){
    stringstream ligne;
    if(vn!=-1){
        ligne<<v<<"/"<<vt<<"/"<<vn;
    }else{
        ligne<<v<<"/"<<vt;
    }
    return ligne.str();
}
