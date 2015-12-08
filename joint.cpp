#include "joint.h"
#include <math.h>
#include <sstream>
#include <QGLViewer/qglviewer.h>

using namespace qglviewer;

/**
 * Constructeur de la jointure
 * @brief Joint::Joint
 * @param x
 * @param y
 * @param z
 * @param rotX
 * @param rotY
 * @param rotZ
 */
Joint::Joint(double x, double y, double z, double rotX, double rotY, double rotZ)
{
    frame=new Frame;
    Quaternion qx(Vec(1,0,0), rotX*M_PI/180);
    Quaternion qy(Vec(0,1,0), rotY*M_PI/180);
    Quaternion qz(Vec(0,0,1), rotZ*M_PI/180);
    Quaternion q(qz*qy*qx);
    q.normalize();
    frame->setOrientation(q);
    frame->setPosition(Vec(x, y, z));
    origine=frame;
}

/**
 * Getter de frame
 * @brief Joint::getFrame
 * @return Frame
 */
Frame* Joint::getFrameCourant(){
    return frame;
}

/**
 * Setter de la position de la frame
 * @brief Joint::setPosition
 * @param x
 * @param y
 * @param z
 */
void Joint::setPosition(double x, double y, double z){
    frame->setPosition(Vec(x, y, z));
}

/**
 * Setter de l'orientation de la frame
 * @brief Joint::setRotation
 * @param rotX
 * @param rotY
 * @param rotZ
 */
void Joint::setRotation(double rotX, double rotY, double rotZ){
    Quaternion qx(Vec(1,0,0), rotX*M_PI/180);
    Quaternion qy(Vec(0,1,0), rotY*M_PI/180);
    Quaternion qz(Vec(0,0,1), rotZ*M_PI/180);
    Quaternion q(qz*qy*qx);
    q.normalize();
    frame->setOrientation(q);
}

/**
 * Getter de la frame origine
 * @brief Joint::getFrameOrigine
 * @return Frame origine
 */
Frame* Joint::getFrameOrigine(){
    return origine;
}
