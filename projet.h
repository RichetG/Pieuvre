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
  Projet(string file);

  void parser(string fichier);
  void init();
  void draw();
  void animate();
  GLuint loadTexture(QString filename);

private :
  vector<Vertex>listVertex;
  vector<Texture>listTexture;
  vector<Normale>listNormale;
  vector<Face>listFace;
  vector<TripletFace>listTriplet;
  GLuint texture[1];
  vector<string> split(string sentence, char delimiter);

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
