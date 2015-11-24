#include "texture.h"
#include <sstream>

/**
 * Constructeur Texture
 * @brief Texture::Texture
 * @param x
 * @param y
 */
Texture::Texture(double x, double y){
    this->x=x;
    this->y=y;
}

/**
 * Getter de la coordonnée x
 * @brief Texture::getX
 * @return x
 */
double Texture::getX(){
    return x;
}

/**
 * Getter de la coordonnée y
 * @brief Texture::getY
 * @return y
 */
double Texture::getY(){
    return y;
}

/**
 * Setter de la coordonnée x
 * @brief Texture::setX
 * @param x
 */
void Texture::setX(double x){
    this->x=x;
}

/**
 * Setter de la coordonnée y
 * @brief Texture::setY
 * @param y
 */
void Texture::setY(double y){
    this->y=y;
}

/**
 * Impression d'une texture "vt x y"
 * @brief Texture::print
 * @return une texture au format obj
 */
string Texture::print(){
    stringstream ligne;
    ligne<<"vt "<<x<<" "<<y;
    return ligne.str();
}

