#include "projet.h"
#include <fstream>
#include <iostream>
#include <sstream>

using namespace qglviewer;
using namespace std;

///////////////////////   V i e w e r  ///////////////////////


void Viewer::init()
{
  /*restoreStateFromFile();
  glDisable(GL_LIGHTING);
  nbPoint = 4;
  points = new Point[nbPoint];
  glPointSize(5.0);
  setGridIsDrawn();
  startAnimation();*/
}

void Viewer::draw()
{
 /* glBegin(GL_POINTS);
  for (int i=0; i<nbPoint; i++)
   points[i].draw();
  glEnd();*/
}

///////////////////////   Projet   ///////////////////////////////

Projet::Projet()
{
  init();
}

void Projet::parser(string file)
{
    listVertex.clear();
    listNormale.clear();
    listFace.clear();
    listTexture.clear();
    ifstream fichier(file.c_str(), ios::in | ios::binary);
    string ligne;
    if(fichier){
        while(getline(fichier, ligne)){
            if(ligne.compare(0, 2, "v ")==0){
                vector<string>mots=split(ligne, ' ');
                Vertex *vertex=new Vertex(std::atof(mots.at(1).c_str()), std::atof(mots.at(2).c_str()),std::atof(mots.at(3).c_str()));
                listVertex.push_back(*vertex);
                cout<<vertex->print()<<endl;
            }else if(ligne.compare(0, 2, "vt")==0){
                vector<string>mots=split(ligne, ' ');
                Texture *texture=new Texture(std::atof(mots.at(1).c_str()), std::atof(mots.at(2).c_str()));
                listTexture.push_back(*texture);
                cout<<texture->print()<<endl;
            }else if(ligne.compare(0, 2, "vn")==0){
                vector<string>mots=split(ligne, ' ');
                Normale *normale=new Normale(std::atof(mots.at(1).c_str()), std::atof(mots.at(2).c_str()),std::atof(mots.at(3).c_str()));
                listNormale.push_back(*normale);
                cout<<normale->print()<<endl;
            }else if(ligne.compare(0, 2, "f ")==0){
                vector<string>mots=split(ligne, ' ');
                Face *face=new Face();
                vector<string>index;
                for(int i=1; i<mots.size(); i++){
                    index=split(mots.at(i), '/');
                    if(index.size()==2){
                        TripletFace *triplet=new TripletFace(std::atof(index.at(0).c_str()), std::atof(index.at(1).c_str()));
                        face->add(*triplet);
                    }else{
                        TripletFace *triplet=new TripletFace(std::atof(index.at(0).c_str()), std::atof(index.at(1).c_str()), std::atof(index.at(2).c_str()));
                        face->add(*triplet);
                    }

                }
                listFace.push_back(*face);
                cout<<face->print()<<endl;
            }
        }
    }
}

void Projet::draw()
{
 /* glColor3f(1.0,0.0, 0.0);
  glVertex3fv(pos_);*/
}


void Projet::init()
{
  //pos_ = Vec(0.4*rand()/RAND_MAX, 0.4*rand()/RAND_MAX, 0.4*rand()/RAND_MAX);
}

vector<string> Projet::split(string sentence, char delimiter){
    vector<string>tmp;
    istringstream iss(sentence);
    string mot;
    while(std::getline(iss, mot, delimiter)){
        tmp.push_back(mot);
    }
    return tmp;
}
