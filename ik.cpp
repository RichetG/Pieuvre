#include "ik.h"
#include "joint.h"
#include <cmath>

using namespace std;

ik::ik()
{

}

// calcul sur nbIterations de la position du point currentLink+1 avec la cinematique inverse
// implementation de l'algorithme CCD (Cyclic Coordinate Descent)
void ik::computeSinglePosition(std::vector<Joint*> &joints, int currentLink, qglviewer::Vec &desiredEnd, int nbIteration)
{
    // LOCAL VARIABLES DECLARATION
    qglviewer::Vec          rootPosition, currentEnd, finalEnd, targetVector, currentVector, computeVector, crossResult;
    double                  cosAngle, turnAngle, turnAngleDeg;
    qglviewer::Quaternion   q;

    //int cpt = 0;
    //while(cpt < nbIteration)
    //{

    // POSITION OF THE ROOT OF THIS LINK
    rootPosition = joints.at(currentLink)->getPosition();
    //std::cout << "rootPosition (" << rootPosition[0] << ", " << rootPosition[1] << ", " << rootPosition[2] << ")" << endl;

    // POSITION OF THE END EFFECTOR
    currentEnd = joints.at(currentLink + 1)->getPosition();
    //std::cout << "currentEnd (" << currentEnd[0] << ", " << currentEnd[1] << ", " << currentEnd[2] << ")" << endl;

    // CREATE THE VECTOR TO THE CURRENT EFFECTOR POS
    currentVector = currentEnd - rootPosition;
    //std::cout << "currentVector (" << currentVector[0] << ", " << currentVector[1] << ", " << currentVector[2] << ")" << endl;

    // CREATE THE DESIRED EFFECTOR POSITION VECTOR
    targetVector = desiredEnd - rootPosition;
    //std::cout << "targetVector (" << targetVector[0] << ", " << targetVector[1] << ", " << targetVector[2] << ")" << endl;


    // CURRENT EFFECTOR POSITION AND DESIRED POSITION NORMALIZATION
    currentVector.normalize();
    //std::cout << "currentVector normalized (" << currentVector[0] << ", " << currentVector[1] << ", " << currentVector[2] << ")" << endl;
    targetVector.normalize();
    //std::cout << "targetVector normalized (" << targetVector[0] << ", " << targetVector[1] << ", " << targetVector[2] << ")" << endl;

    // DOT PRODUCT OF TARGETVECTOR AND CURRENTVECTOR
    cosAngle = targetVector * currentVector;
    //std::cout << "cosAngle = " << cosAngle << endl;

    // CROSS PRODUCT OF CURRENTVECTOR AND TARGETVECTOR
    crossResult = currentVector ^ targetVector;
    //std::cout << "crossResult = " << crossResult << endl;

    // CROSSRESULT NORMALIZATION
    crossResult.normalize();
    //std::cout << "crossResult normalized = " << crossResult << endl;

    // GET THE ANGLE
    turnAngle = acos((float)cosAngle);
    //std::cout << "turnAngle = " << turnAngle << " rad" << endl;
    // CONVERT TO DEGREES
    turnAngleDeg = turnAngle / M_PI * 180;
    //std::cout << "turnAngleDeg = " << turnAngleDeg << " deg" << endl;

    q.setAxisAngle(crossResult, turnAngle);
    joints.at(currentLink+1)->rotateAroundPoint(q, rootPosition);

    //cpt++;
    //}
    // SETUP THE QUATERNION Q


    // GET THE COMPUTE VECTOR
    //computeVector = q * currentVector;
    //std::cout << "computeVector (" << computeVector[0] << ", " << computeVector[1] << ", " << computeVector[2] << ")" << endl;

    // GET THE FINAL END POSITION
    //finalEnd[0] = rootPosition[0] + computeVector[0];
    //finalEnd[1] = rootPosition[1] + computeVector[1];
    //finalEnd[2] = rootPosition[2] + computeVector[2];
    //std::cout << "finalEnd (" << finalEnd[0] << ", " << finalEnd[1] << ", " << finalEnd[2] << ")" << endl;
}



