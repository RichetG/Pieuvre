#include "normale.h"
#include <sstream>

Normale::Normale(double x, double y, double z){
    this->x=x;
    this->y=y;
    this->z=z;
}

double Normale::getX(){
    return x;
}

double Normale::getY(){
    return y;
}

double Normale::getZ(){
    return z;
}

void Normale::setX(double x){
    this->x=x;
}

void Normale::setY(double y){
    this->y=y;
}

void Normale::setZ(double z){
    this->z=z;
}

string Normale::print(){
    stringstream ligne;
    ligne<<"vn "<<x<<" "<<y<<" "<<z;
    return ligne.str();
}

