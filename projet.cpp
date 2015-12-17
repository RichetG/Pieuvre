#include "projet.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <GL/glu.h>
#include <GL/gl.h>

//using namespace qglviewer;
using namespace std;

///////////////////////   V i e w e r  ///////////////////////


void Viewer::init()
{
  restoreStateFromFile();
  glDisable(GL_LIGHTING);
  projet =new Projet("C:\\Users\\guillaume\\Documents\\Matiere informatique\\M2\\inf2344\\libQGLViewer-2.6.3\\examples\\Pieuvre\\Maillage\\Poulpo.obj");
  GLuint texture=projet->loadTexture("C:\\Users\\guillaume\\Documents\\Matiere informatique\\M2\\inf2344\\libQGLViewer-2.6.3\\examples\\Pieuvre\\Texture\\Poulpo.jpg");
  vector<string> listFilePoids;
  listFilePoids.push_back("C:\\Users\\guillaume\\Documents\\Matiere informatique\\M2\\inf2344\\libQGLViewer-2.6.3\\examples\\Pieuvre\\Script_Skelet\\Poulpe.maSkelet_Bassin.wei");
  listFilePoids.push_back("C:\\Users\\guillaume\\Documents\\Matiere informatique\\M2\\inf2344\\libQGLViewer-2.6.3\\examples\\Pieuvre\\Script_Skelet\\Poulpe.maSkelet_Head.wei");
  listFilePoids.push_back("C:\\Users\\guillaume\\Documents\\Matiere informatique\\M2\\inf2344\\libQGLViewer-2.6.3\\examples\\Pieuvre\\Script_Skelet\\Poulpe.maSkelet_Tenta1os1.wei");
  listFilePoids.push_back("C:\\Users\\guillaume\\Documents\\Matiere informatique\\M2\\inf2344\\libQGLViewer-2.6.3\\examples\\Pieuvre\\Script_Skelet\\Poulpe.maSkelet_Tenta1os2.wei");
  listFilePoids.push_back("C:\\Users\\guillaume\\Documents\\Matiere informatique\\M2\\inf2344\\libQGLViewer-2.6.3\\examples\\Pieuvre\\Script_Skelet\\Poulpe.maSkelet_Tenta1os3.wei");
  listFilePoids.push_back("C:\\Users\\guillaume\\Documents\\Matiere informatique\\M2\\inf2344\\libQGLViewer-2.6.3\\examples\\Pieuvre\\Script_Skelet\\Poulpe.maSkelet_Tenta1os4.wei");
  listFilePoids.push_back("C:\\Users\\guillaume\\Documents\\Matiere informatique\\M2\\inf2344\\libQGLViewer-2.6.3\\examples\\Pieuvre\\Script_Skelet\\Poulpe.maSkelet_Tenta1os5.wei");
  listFilePoids.push_back("C:\\Users\\guillaume\\Documents\\Matiere informatique\\M2\\inf2344\\libQGLViewer-2.6.3\\examples\\Pieuvre\\Script_Skelet\\Poulpe.maSkelet_Tenta1os6.wei");
  listFilePoids.push_back("C:\\Users\\guillaume\\Documents\\Matiere informatique\\M2\\inf2344\\libQGLViewer-2.6.3\\examples\\Pieuvre\\Script_Skelet\\Poulpe.maSkelet_Tenta2os1.wei");
  listFilePoids.push_back("C:\\Users\\guillaume\\Documents\\Matiere informatique\\M2\\inf2344\\libQGLViewer-2.6.3\\examples\\Pieuvre\\Script_Skelet\\Poulpe.maSkelet_Tenta2os2.wei");
  listFilePoids.push_back("C:\\Users\\guillaume\\Documents\\Matiere informatique\\M2\\inf2344\\libQGLViewer-2.6.3\\examples\\Pieuvre\\Script_Skelet\\Poulpe.maSkelet_Tenta2os3.wei");
  listFilePoids.push_back("C:\\Users\\guillaume\\Documents\\Matiere informatique\\M2\\inf2344\\libQGLViewer-2.6.3\\examples\\Pieuvre\\Script_Skelet\\Poulpe.maSkelet_Tenta2os4.wei");
  listFilePoids.push_back("C:\\Users\\guillaume\\Documents\\Matiere informatique\\M2\\inf2344\\libQGLViewer-2.6.3\\examples\\Pieuvre\\Script_Skelet\\Poulpe.maSkelet_Tenta2os5.wei");
  listFilePoids.push_back("C:\\Users\\guillaume\\Documents\\Matiere informatique\\M2\\inf2344\\libQGLViewer-2.6.3\\examples\\Pieuvre\\Script_Skelet\\Poulpe.maSkelet_Tenta2os6.wei");
  listFilePoids.push_back("C:\\Users\\guillaume\\Documents\\Matiere informatique\\M2\\inf2344\\libQGLViewer-2.6.3\\examples\\Pieuvre\\Script_Skelet\\Poulpe.maSkelet_Tenta3os1.wei");
  listFilePoids.push_back("C:\\Users\\guillaume\\Documents\\Matiere informatique\\M2\\inf2344\\libQGLViewer-2.6.3\\examples\\Pieuvre\\Script_Skelet\\Poulpe.maSkelet_Tenta3os2.wei");
  listFilePoids.push_back("C:\\Users\\guillaume\\Documents\\Matiere informatique\\M2\\inf2344\\libQGLViewer-2.6.3\\examples\\Pieuvre\\Script_Skelet\\Poulpe.maSkelet_Tenta3os3.wei");
  listFilePoids.push_back("C:\\Users\\guillaume\\Documents\\Matiere informatique\\M2\\inf2344\\libQGLViewer-2.6.3\\examples\\Pieuvre\\Script_Skelet\\Poulpe.maSkelet_Tenta3os4.wei");
  listFilePoids.push_back("C:\\Users\\guillaume\\Documents\\Matiere informatique\\M2\\inf2344\\libQGLViewer-2.6.3\\examples\\Pieuvre\\Script_Skelet\\Poulpe.maSkelet_Tenta3os5.wei");
  listFilePoids.push_back("C:\\Users\\guillaume\\Documents\\Matiere informatique\\M2\\inf2344\\libQGLViewer-2.6.3\\examples\\Pieuvre\\Script_Skelet\\Poulpe.maSkelet_Tenta3os6.wei");
  listFilePoids.push_back("C:\\Users\\guillaume\\Documents\\Matiere informatique\\M2\\inf2344\\libQGLViewer-2.6.3\\examples\\Pieuvre\\Script_Skelet\\Poulpe.maSkelet_Tenta4os1.wei");
  listFilePoids.push_back("C:\\Users\\guillaume\\Documents\\Matiere informatique\\M2\\inf2344\\libQGLViewer-2.6.3\\examples\\Pieuvre\\Script_Skelet\\Poulpe.maSkelet_Tenta4os2.wei");
  listFilePoids.push_back("C:\\Users\\guillaume\\Documents\\Matiere informatique\\M2\\inf2344\\libQGLViewer-2.6.3\\examples\\Pieuvre\\Script_Skelet\\Poulpe.maSkelet_Tenta4os3.wei");
  listFilePoids.push_back("C:\\Users\\guillaume\\Documents\\Matiere informatique\\M2\\inf2344\\libQGLViewer-2.6.3\\examples\\Pieuvre\\Script_Skelet\\Poulpe.maSkelet_Tenta4os4.wei");
  listFilePoids.push_back("C:\\Users\\guillaume\\Documents\\Matiere informatique\\M2\\inf2344\\libQGLViewer-2.6.3\\examples\\Pieuvre\\Script_Skelet\\Poulpe.maSkelet_Tenta4os5.wei");
  listFilePoids.push_back("C:\\Users\\guillaume\\Documents\\Matiere informatique\\M2\\inf2344\\libQGLViewer-2.6.3\\examples\\Pieuvre\\Script_Skelet\\Poulpe.maSkelet_Tenta4os6.wei");
  listFilePoids.push_back("C:\\Users\\guillaume\\Documents\\Matiere informatique\\M2\\inf2344\\libQGLViewer-2.6.3\\examples\\Pieuvre\\Script_Skelet\\Poulpe.maSkelet_Tenta5os1.wei");
  listFilePoids.push_back("C:\\Users\\guillaume\\Documents\\Matiere informatique\\M2\\inf2344\\libQGLViewer-2.6.3\\examples\\Pieuvre\\Script_Skelet\\Poulpe.maSkelet_Tenta5os2.wei");
  listFilePoids.push_back("C:\\Users\\guillaume\\Documents\\Matiere informatique\\M2\\inf2344\\libQGLViewer-2.6.3\\examples\\Pieuvre\\Script_Skelet\\Poulpe.maSkelet_Tenta5os3.wei");
  listFilePoids.push_back("C:\\Users\\guillaume\\Documents\\Matiere informatique\\M2\\inf2344\\libQGLViewer-2.6.3\\examples\\Pieuvre\\Script_Skelet\\Poulpe.maSkelet_Tenta5os4.wei");
  listFilePoids.push_back("C:\\Users\\guillaume\\Documents\\Matiere informatique\\M2\\inf2344\\libQGLViewer-2.6.3\\examples\\Pieuvre\\Script_Skelet\\Poulpe.maSkelet_Tenta5os5.wei");
  listFilePoids.push_back("C:\\Users\\guillaume\\Documents\\Matiere informatique\\M2\\inf2344\\libQGLViewer-2.6.3\\examples\\Pieuvre\\Script_Skelet\\Poulpe.maSkelet_Tenta5os6.wei");
  projet->poids(listFilePoids);
  projet->joints("C:\\Users\\guillaume\\Documents\\Matiere informatique\\M2\\inf2344\\libQGLViewer-2.6.3\\examples\\Pieuvre\\Script_Mkf\\Poulpo.mkf");
  setGridIsDrawn();
  startAnimation();

}

void Viewer::draw()
{
    projet->draw();
}

void Viewer::animate()
{

}

///////////////////////   Projet   ///////////////////////////////

Projet::Projet(string file)
{
  parser(file);
}

/**
 * Récupération du contenue d'un fichier obj
 * @brief Projet::parser
 * @param file
 */
void Projet::parser(string file)
{
    listVertex.clear();
    listNormale.clear();
    listFace.clear();
    listTexture.clear();
    listOrigine.clear();
    ifstream fichier(file.c_str(), ios::in | ios::binary);
    string ligne;
    if(fichier){
        while(getline(fichier, ligne)){
            if(ligne.compare(0, 2, "v ")==0){
                vector<string>mots=split(ligne, ' ');
                Vertex *vertex=new Vertex(std::atof(mots.at(1).c_str()), std::atof(mots.at(2).c_str()),std::atof(mots.at(3).c_str()));
                Vertex *vertexCopie=new Vertex(std::atof(mots.at(1).c_str()), std::atof(mots.at(2).c_str()),std::atof(mots.at(3).c_str()));
                listVertex.push_back(*vertex);
                listOrigine.push_back(*vertexCopie);
            }else if(ligne.compare(0, 2, "vt")==0){
                vector<string>mots=split(ligne, ' ');
                Texture *texture=new Texture(std::atof(mots.at(1).c_str()), std::atof(mots.at(2).c_str()));
                listTexture.push_back(*texture);
            }else if(ligne.compare(0, 2, "vn")==0){
                vector<string>mots=split(ligne, ' ');
                Normale *normale=new Normale(std::atof(mots.at(1).c_str()), std::atof(mots.at(2).c_str()),std::atof(mots.at(3).c_str()));
                listNormale.push_back(*normale);
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
            }
        }
    }
}

void Projet::draw()
{
    glLineWidth(1.0);
    for(int i=0; i<listFace.size(); i++){
        glBegin(GL_POLYGON);
        for(int j=0; j<listFace.at(i).size(); j++){
            Vertex vertex=listVertex.at(listFace.at(i).at(j).getV()-1);
            Texture texture=listTexture.at(listFace.at(i).at(j).getVT()-1);
            Normale normale=listNormale.at(listFace.at(i).at(j).getVN()-1);
            glNormal3d(normale.getX(), normale.getY(), normale.getZ());
            glTexCoord2d(texture.getX(), texture.getY());
            glVertex3d(vertex.getX(), vertex.getY(), vertex.getZ());
        }
        glEnd();
        glFlush();
    }
}


void Projet::init()
{

}

void Projet::animate()
{
    /*for(int i=0; i<listVertex.size(); i++){
        posVertexCourant=null;
        for(int j=0; j<jointure.size(); j++){
            Vec temp;
            temp=jointure.at(j).getFrameOrigine()->coordinateOf(listOrigine.at(i));

        }
    }*/
}

/**
 * Chargement de la texture
 * @brief Projet::loadTexture
 * @param filename
 * @param width
 * @param height
 * @return
 */
GLuint Projet::loadTexture(QString filename){
    QImage image(filename, "JPG");
    QImage img=QGLWidget::convertToGLFormat(image);
    glEnable(GL_TEXTURE_2D);
    glGenTextures(1, &texture[0]);
    glBindTexture(GL_TEXTURE_2D, texture[0]);
    glTexImage2D (GL_TEXTURE_2D, 0, GL_RGB, img.width(), img.height(), 0, GL_RGBA, GL_UNSIGNED_BYTE, img.bits());
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    return texture[0];
}

/**
 * Séparation d'une phrase à partir d'un caractère
 * @brief Projet::split
 * @param sentence
 * @param delimiter
 * @return liste de mots
 */
vector<string> Projet::split(string sentence, char delimiter){
    vector<string>tmp;
    istringstream iss(sentence);
    string mot;
    while(std::getline(iss, mot, delimiter)){
        tmp.push_back(mot);
    }
    return tmp;
}

void Projet::poids(vector<string> listes){
    for(int i=0; i<listes.size(); i++){
        ifstream fichier(listes.at(i).c_str(), ios::in | ios::binary);
        string ligne;
        if(fichier){
            while(getline(fichier, ligne)){
                vector<string> tab=split(ligne, ' ');
                vector<double> tmp;
                for(int j=0; j<listVertex.size(); j++){
                    tmp.clear();
                    tmp=listVertex.at(j).getPoids();
                    tmp.push_back(std::atof(tab.at(j).c_str()));
                    listVertex.at(j).setPoids(tmp);
                }
            }
        }
    }
}

void Projet::joints(string file){
    ifstream fichier(file.c_str(), ios::in | ios::binary);
    string ligne;
    if(fichier){
        while(getline(fichier, ligne)){
            vector<string> tab=split(ligne, ' ');
            vector<double> tmp;
            for(int i=0; i<tab.size(); i++){
                if(i%6==0){
                    Joint *joint=new Joint(std::atof(tab.at(i).c_str()), std::atof(tab.at(i+1).c_str()), std::atof(tab.at(i+2).c_str()), std::atof(tab.at(i+3).c_str()), std::atof(tab.at(i+4).c_str()), std::atof(tab.at(i+5).c_str()));
                    jointure.push_back(joint);
                }
            }
        }
    }
}
