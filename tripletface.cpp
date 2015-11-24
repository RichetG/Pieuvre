#include "tripletface.h"
#include <sstream>

/**
 * Constructeur TripletFace
 * @brief TripletFace::TripletFace
 * @param v
 * @param vt
 * @param vn
 */
TripletFace::TripletFace(int v, int vt, int vn){
    this->v=v;
    this->vt=vt;
    this->vn=vn;
}

/**
 * Constructeur TripletFace
 * @brief TripletFace::TripletFace
 * @param v
 * @param vt
 */
TripletFace::TripletFace(int v, int vt){
    this->v=v;
    this->vt=vt;
    vn=-1;
}

/**
 * Getter index vertex
 * @brief TripletFace::getV
 * @return index Vertex
 */
int TripletFace::getV(){
    return v;
}

/**
 * Getteer index texture
 * @brief TripletFace::getVT
 * @return index texture
 */
int TripletFace::getVT(){
    return vt;
}

/**
 * Getter index normale
 * @brief TripletFace::getVN
 * @return index normale
 */
int TripletFace::getVN(){
    return vn;
}

/**
 * Setter index vertex
 * @brief TripletFace::setV
 * @param v
 */
void TripletFace::setV(int v){
    this->v=v;
}

/**
 * Setter index texture
 * @brief TripletFace::setVT
 * @param vt
 */
void TripletFace::setVT(int vt){
    this->vt=vt;
}

/**
 * Setter index normale
 * @brief TripletFace::setVN
 * @param vn
 */
void TripletFace::setVN(int vn){
    this->vn=vn;
}

/**
 * Impression du triplet "v1/t1/n1"
 * @brief TripletFace::print
 * @return le triplet au format obj
 */
string TripletFace::print(){
    stringstream ligne;
    if(vn!=-1){
        ligne<<v<<"/"<<vt<<"/"<<vn;
    }else{
        ligne<<v<<"/"<<vt;
    }
    return ligne.str();
}
