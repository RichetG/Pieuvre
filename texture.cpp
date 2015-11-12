#include "texture.h"
#include <sstream>

Texture::Texture(double x, double y){
    this->x=x;
    this->y=y;
}

double Texture::getX(){
    return x;
}

double Texture::getY(){
    return y;
}

void Texture::setX(double x){
    this->x=x;
}

void Texture::setY(double y){
    this->y=y;
}

string Texture::print(){
    stringstream ligne;
    ligne<<"vt "<<x<<" "<<y;
    return ligne.str();
}

