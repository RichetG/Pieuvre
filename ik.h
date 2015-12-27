#ifndef IK_H
#define IK_H

#include "joint.h"
#include <QGLViewer/qglviewer.h>

class ik
{
public:
    ik();
    void computeSinglePosition(std::vector<Joint*> &joints, int currentLink, qglviewer::Vec &desiredEnd, int nbIteration = 1);
};

#endif // IK_H
