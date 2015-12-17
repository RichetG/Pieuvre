#ifndef JOINT
#define JOINT

//#include <qglviewer.h>
#include <QGLViewer/qglviewer.h>

using namespace qglviewer;

//class qglviewer::ManipulatedFrame;

class Joint{

public:
    Joint(double x, double y, double z, double rotX, double rotY, double rotZ);
    Frame* getFrameCourant();
    double getX();
    double getY();
    double getZ();
    void setPosition(double x, double y, double z);
    void setRotation(double rotX, double rotY, double rotZ);
    void rotateAroundPoint(Quaternion & rotation, Vec & point);
    Vec getPosition();
    Frame* getFrameOrigine();

private:
    double x, y, z, rotX, rotY, rotZ;
    Frame *origine, *frame;
};

#endif
