#ifndef PROJET
#define PROJET

#include <QGLViewer/qglviewer.h>
#include <vector>
#include "vertex.h"
#include "face.h"
#include "normale.h"
#include "texture.h"
#include "joint.h"
using namespace std;

class Projet
{
public :
  Projet(string file);

  void parser(string fichier);
  void init();
  void draw();
  void animate();
  GLuint loadTexture(QString filename);
  void poids(vector<string> listes);
  void joints(string file);

private :
  vector<Vertex>listVertex, listOrigine;
  vector<Texture>listTexture;
  vector<Normale>listNormale;
  vector<Face>listFace;
  vector<TripletFace>listTriplet;
  GLuint texture[1];
  vector<string> split(string sentence, char delimiter);
  vector<Joint*>jointure;
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
};

#endif
