#include <QGLViewer/qglviewer.h>
#include <vector>
#include "vertex.h"
#include "face.h"
#include "normale.h"
#include "texture.h"
using namespace std;

class Projet
{
public :
  Projet();

  void parser(string fichier);
  void init();
  void draw();

private :
  vector<Vertex>listVertex;
  vector<Texture>listTexture;
  vector<Normale>listNormale;
  vector<Face>listFace;
  vector<TripletFace>listTriplet;
  vector<string> split(string sentence, char delimiter);
};

class Viewer : public QGLViewer
{
protected :
  virtual void draw();
  virtual void init();

private:
   /* int nbPoint;
    Point* points;*/
};
