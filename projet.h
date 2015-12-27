#ifndef PROJET
#define PROJET

#include <QGLViewer/qglviewer.h>
#include <vector>
#include "vertex.h"
#include "face.h"
#include "normale.h"
#include "texture.h"
#include "joint.h"

#include "ik.h"
using namespace std;

class Projet
{
public :
  Projet(string file);

  void parser(string fichier);
  void init();
  void draw();
  void animate();
  void loadTexture(GLuint texture, QString filename);
  GLuint choixTexture(int i);
 // GLuint loadTexture(QString filename);
  void poids(vector<string> listes);
  void joints(string file);
  vector<Vertex>listVertex, listOrigine;
  vector<Joint*>jointure;

private :
  vector<Texture>listTexture;
  vector<Normale>listNormale;
  vector<Face>listFace;
  vector<TripletFace>listTriplet;
  vector<string> split(string sentence, char delimiter);

  Vec posVertexCourant;
};

class Viewer : public QGLViewer
{
protected :
  virtual void draw();
  virtual void init();
  virtual void animate();

private:
    Projet* projet;
    GLuint texture[6];
    int random=0, cpt=0;

    std::vector<qglviewer::Vec> chain;
    std::vector<Joint*> joints;
    ik inv_kinematic;
    char c;
    Vec butTenta1, butTenta2, butTenta3, butTenta4, butTenta5;
    double angle;
};

#endif
