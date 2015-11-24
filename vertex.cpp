#include "vertex.h"
#include <sstream>

/**
 * Constructeur Vertex
 * @brief Vertex::Vertex
 * @param x
 * @param y
 * @param z
 */
Vertex::Vertex(double x, double y, double z){
    this->x=x;
    this->y=y;
    this->z=z;
}

/**
 * Getter de la coordonnée x
 * @brief Vertex::getX
 * @return x
 */
double Vertex::getX(){
    return x;
}

/**
 * Getter de la coordonnée y
 * @brief Vertex::getY
 * @return y
 */
double Vertex::getY(){
    return y;
}

/**
 * Getter de la coordonnée z
 * @brief Vertex::getZ
 * @return z
 */
double Vertex::getZ(){
    return z;
}

/**
 * Setter de la coordonnée x
 * @brief Vertex::setX
 * @param x
 */
void Vertex::setX(double x){
    this->x=x;
}

/**
 * Setter de  la coordonnée y
 * @brief Vertex::setY
 * @param y
 */
void Vertex::setY(double y){
    this->y=y;
}

/**
 * Setter de la coordonnée z
 * @brief Vertex::setZ
 * @param z
 */
void Vertex::setZ(double z){
    this->z=z;
}

/**
 * Impression d'un vertex "v x y z"
 * @brief Vertex::print
 * @return un vertex au format obj
 */
string Vertex::print(){
    stringstream ligne;
    ligne<<"v "<<x<<" "<<y<<" "<<z;
    return ligne.str();
}
