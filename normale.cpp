#include "normale.h"
#include <sstream>

/**
 * Constructeur Normale
 * @brief Normale::Normale
 * @param x
 * @param y
 * @param z
 */
Normale::Normale(double x, double y, double z){
    this->x=x;
    this->y=y;
    this->z=z;
}

/**
 * Getter de la coordonnée x
 * @brief Normale::getX
 * @return x
 */
double Normale::getX(){
    return x;
}

/**
 * Getter de la coordonnée y
 * @brief Normale::getY
 * @return y
 */
double Normale::getY(){
    return y;
}

/**
 * Getter de la coordonnée z
 * @brief Normale::getZ
 * @return z
 */
double Normale::getZ(){
    return z;
}

/**
 * Setter de la coordonnée x
 * @brief Normale::setX
 * @param x
 */
void Normale::setX(double x){
    this->x=x;
}

/**
 * Setter de la coordonnée y
 * @brief Normale::setY
 * @param y
 */
void Normale::setY(double y){
    this->y=y;
}

/**
 * Setter de la coordonnée z
 * @brief Normale::setZ
 * @param z
 */
void Normale::setZ(double z){
    this->z=z;
}

/**
 * Impression d'une normale "vn x y z"
 * @brief Normale::print
 * @return une normale au format obj
 */
string Normale::print(){
    stringstream ligne;
    ligne<<"vn "<<x<<" "<<y<<" "<<z;
    return ligne.str();
}

