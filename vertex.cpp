#include "vertex.h"
#include <sstream>

Vertex::Vertex(double x, double y, double z){
    this->x=x;
    this->y=y;
    this->z=z;
}

double Vertex::getX(){
    return x;
}

double Vertex::getY(){
    return y;
}

double Vertex::getZ(){
    return z;
}

void Vertex::setX(double x){
    this->x=x;
}

void Vertex::setY(double y){
    this->y=y;
}

void Vertex::setZ(double z){
    this->z=z;
}

string Vertex::print(){
    stringstream ligne;
    ligne<<"v "<<x<<" "<<y<<" "<<z;
    return ligne.str();
}
