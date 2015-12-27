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
  angle = 270;
  inv_kinematic = ik();
  restoreStateFromFile();
  glDisable(GL_LIGHTING);
  projet =new Projet("C:\\Users\\guillaume\\Documents\\Matiere informatique\\M2\\inf2344\\libQGLViewer-2.6.3\\examples\\Pieuvre\\Maillage\\Poulpo.obj");
  glGenTextures(6, texture);
  projet->loadTexture(texture[0], "C:\\Users\\guillaume\\Documents\\Matiere informatique\\M2\\inf2344\\libQGLViewer-2.6.3\\examples\\Pieuvre\\Texture\\PoulpoGreen.jpg");
  projet->loadTexture(texture[1], "C:\\Users\\guillaume\\Documents\\Matiere informatique\\M2\\inf2344\\libQGLViewer-2.6.3\\examples\\Pieuvre\\Texture\\PoulpoRed.jpg");
  projet->loadTexture(texture[2], "C:\\Users\\guillaume\\Documents\\Matiere informatique\\M2\\inf2344\\libQGLViewer-2.6.3\\examples\\Pieuvre\\Texture\\PoulpoBlue.jpg");
  projet->loadTexture(texture[3], "C:\\Users\\guillaume\\Documents\\Matiere informatique\\M2\\inf2344\\libQGLViewer-2.6.3\\examples\\Pieuvre\\Texture\\PoulpoYellow.jpg");
  projet->loadTexture(texture[4], "C:\\Users\\guillaume\\Documents\\Matiere informatique\\M2\\inf2344\\libQGLViewer-2.6.3\\examples\\Pieuvre\\Texture\\PoulpoPink.jpg");
  projet->loadTexture(texture[5], "C:\\Users\\guillaume\\Documents\\Matiere informatique\\M2\\inf2344\\libQGLViewer-2.6.3\\examples\\Pieuvre\\Texture\\PoulpoOrange.jpg");
  // GLuint texture=projet->loadTexture("C:\\Users\\guillaume\\Documents\\Matiere informatique\\M2\\inf2344\\libQGLViewer-2.6.3\\examples\\Pieuvre\\Texture\\PoulpoGreen.jpg");
  vector<string> listFilePoids;
  listFilePoids.push_back("C:\\Users\\guillaume\\Documents\\Matiere informatique\\M2\\inf2344\\libQGLViewer-2.6.3\\examples\\Pieuvre\\Script_Skelet\\Poulpo.maSkelet_Bassin.wei");
  listFilePoids.push_back("C:\\Users\\guillaume\\Documents\\Matiere informatique\\M2\\inf2344\\libQGLViewer-2.6.3\\examples\\Pieuvre\\Script_Skelet\\Poulpo.maSkelet_Head.wei");
  listFilePoids.push_back("C:\\Users\\guillaume\\Documents\\Matiere informatique\\M2\\inf2344\\libQGLViewer-2.6.3\\examples\\Pieuvre\\Script_Skelet\\Poulpo.maSkelet_Tenta1os1.wei");
  listFilePoids.push_back("C:\\Users\\guillaume\\Documents\\Matiere informatique\\M2\\inf2344\\libQGLViewer-2.6.3\\examples\\Pieuvre\\Script_Skelet\\Poulpo.maSkelet_Tenta1os2.wei");
  listFilePoids.push_back("C:\\Users\\guillaume\\Documents\\Matiere informatique\\M2\\inf2344\\libQGLViewer-2.6.3\\examples\\Pieuvre\\Script_Skelet\\Poulpo.maSkelet_Tenta1os3.wei");
  listFilePoids.push_back("C:\\Users\\guillaume\\Documents\\Matiere informatique\\M2\\inf2344\\libQGLViewer-2.6.3\\examples\\Pieuvre\\Script_Skelet\\Poulpo.maSkelet_Tenta1os4.wei");
  listFilePoids.push_back("C:\\Users\\guillaume\\Documents\\Matiere informatique\\M2\\inf2344\\libQGLViewer-2.6.3\\examples\\Pieuvre\\Script_Skelet\\Poulpo.maSkelet_Tenta1os5.wei");
  listFilePoids.push_back("C:\\Users\\guillaume\\Documents\\Matiere informatique\\M2\\inf2344\\libQGLViewer-2.6.3\\examples\\Pieuvre\\Script_Skelet\\Poulpo.maSkelet_Tenta1os6.wei");
  listFilePoids.push_back("C:\\Users\\guillaume\\Documents\\Matiere informatique\\M2\\inf2344\\libQGLViewer-2.6.3\\examples\\Pieuvre\\Script_Skelet\\Poulpo.maSkelet_Tenta2os1.wei");
  listFilePoids.push_back("C:\\Users\\guillaume\\Documents\\Matiere informatique\\M2\\inf2344\\libQGLViewer-2.6.3\\examples\\Pieuvre\\Script_Skelet\\Poulpo.maSkelet_Tenta2os2.wei");
  listFilePoids.push_back("C:\\Users\\guillaume\\Documents\\Matiere informatique\\M2\\inf2344\\libQGLViewer-2.6.3\\examples\\Pieuvre\\Script_Skelet\\Poulpo.maSkelet_Tenta2os3.wei");
  listFilePoids.push_back("C:\\Users\\guillaume\\Documents\\Matiere informatique\\M2\\inf2344\\libQGLViewer-2.6.3\\examples\\Pieuvre\\Script_Skelet\\Poulpo.maSkelet_Tenta2os4.wei");
  listFilePoids.push_back("C:\\Users\\guillaume\\Documents\\Matiere informatique\\M2\\inf2344\\libQGLViewer-2.6.3\\examples\\Pieuvre\\Script_Skelet\\Poulpo.maSkelet_Tenta2os5.wei");
  listFilePoids.push_back("C:\\Users\\guillaume\\Documents\\Matiere informatique\\M2\\inf2344\\libQGLViewer-2.6.3\\examples\\Pieuvre\\Script_Skelet\\Poulpo.maSkelet_Tenta2os6.wei");
  listFilePoids.push_back("C:\\Users\\guillaume\\Documents\\Matiere informatique\\M2\\inf2344\\libQGLViewer-2.6.3\\examples\\Pieuvre\\Script_Skelet\\Poulpo.maSkelet_Tenta3os1.wei");
  listFilePoids.push_back("C:\\Users\\guillaume\\Documents\\Matiere informatique\\M2\\inf2344\\libQGLViewer-2.6.3\\examples\\Pieuvre\\Script_Skelet\\Poulpo.maSkelet_Tenta3os2.wei");
  listFilePoids.push_back("C:\\Users\\guillaume\\Documents\\Matiere informatique\\M2\\inf2344\\libQGLViewer-2.6.3\\examples\\Pieuvre\\Script_Skelet\\Poulpo.maSkelet_Tenta3os3.wei");
  listFilePoids.push_back("C:\\Users\\guillaume\\Documents\\Matiere informatique\\M2\\inf2344\\libQGLViewer-2.6.3\\examples\\Pieuvre\\Script_Skelet\\Poulpo.maSkelet_Tenta3os4.wei");
  listFilePoids.push_back("C:\\Users\\guillaume\\Documents\\Matiere informatique\\M2\\inf2344\\libQGLViewer-2.6.3\\examples\\Pieuvre\\Script_Skelet\\Poulpo.maSkelet_Tenta3os5.wei");
  listFilePoids.push_back("C:\\Users\\guillaume\\Documents\\Matiere informatique\\M2\\inf2344\\libQGLViewer-2.6.3\\examples\\Pieuvre\\Script_Skelet\\Poulpo.maSkelet_Tenta3os6.wei");
  listFilePoids.push_back("C:\\Users\\guillaume\\Documents\\Matiere informatique\\M2\\inf2344\\libQGLViewer-2.6.3\\examples\\Pieuvre\\Script_Skelet\\Poulpo.maSkelet_Tenta4os1.wei");
  listFilePoids.push_back("C:\\Users\\guillaume\\Documents\\Matiere informatique\\M2\\inf2344\\libQGLViewer-2.6.3\\examples\\Pieuvre\\Script_Skelet\\Poulpo.maSkelet_Tenta4os2.wei");
  listFilePoids.push_back("C:\\Users\\guillaume\\Documents\\Matiere informatique\\M2\\inf2344\\libQGLViewer-2.6.3\\examples\\Pieuvre\\Script_Skelet\\Poulpo.maSkelet_Tenta4os3.wei");
  listFilePoids.push_back("C:\\Users\\guillaume\\Documents\\Matiere informatique\\M2\\inf2344\\libQGLViewer-2.6.3\\examples\\Pieuvre\\Script_Skelet\\Poulpo.maSkelet_Tenta4os4.wei");
  listFilePoids.push_back("C:\\Users\\guillaume\\Documents\\Matiere informatique\\M2\\inf2344\\libQGLViewer-2.6.3\\examples\\Pieuvre\\Script_Skelet\\Poulpo.maSkelet_Tenta4os5.wei");
  listFilePoids.push_back("C:\\Users\\guillaume\\Documents\\Matiere informatique\\M2\\inf2344\\libQGLViewer-2.6.3\\examples\\Pieuvre\\Script_Skelet\\Poulpo.maSkelet_Tenta4os6.wei");
  listFilePoids.push_back("C:\\Users\\guillaume\\Documents\\Matiere informatique\\M2\\inf2344\\libQGLViewer-2.6.3\\examples\\Pieuvre\\Script_Skelet\\Poulpo.maSkelet_Tenta5os1.wei");
  listFilePoids.push_back("C:\\Users\\guillaume\\Documents\\Matiere informatique\\M2\\inf2344\\libQGLViewer-2.6.3\\examples\\Pieuvre\\Script_Skelet\\Poulpo.maSkelet_Tenta5os2.wei");
  listFilePoids.push_back("C:\\Users\\guillaume\\Documents\\Matiere informatique\\M2\\inf2344\\libQGLViewer-2.6.3\\examples\\Pieuvre\\Script_Skelet\\Poulpo.maSkelet_Tenta5os3.wei");
  listFilePoids.push_back("C:\\Users\\guillaume\\Documents\\Matiere informatique\\M2\\inf2344\\libQGLViewer-2.6.3\\examples\\Pieuvre\\Script_Skelet\\Poulpo.maSkelet_Tenta5os4.wei");
  listFilePoids.push_back("C:\\Users\\guillaume\\Documents\\Matiere informatique\\M2\\inf2344\\libQGLViewer-2.6.3\\examples\\Pieuvre\\Script_Skelet\\Poulpo.maSkelet_Tenta5os5.wei");
  listFilePoids.push_back("C:\\Users\\guillaume\\Documents\\Matiere informatique\\M2\\inf2344\\libQGLViewer-2.6.3\\examples\\Pieuvre\\Script_Skelet\\Poulpo.maSkelet_Tenta5os6.wei");
  projet->poids(listFilePoids);
  projet->joints("C:\\Users\\guillaume\\Documents\\Matiere informatique\\M2\\inf2344\\libQGLViewer-2.6.3\\examples\\Pieuvre\\Script_Mkf\\Poulpo.mkf");
  setGridIsDrawn();
  startAnimation();
  //ensembles des vecteurs
  for(int i=0; i<projet->listVertex.size(); i++){
     chain.push_back(projet->listVertex.at(i).convertionVertex());
  }
  //ensemble des joints
  for(int i=0; i<projet->jointure.size(); i++){
      joints.push_back(projet->jointure.at(i));
  }
  butTenta1=joints.at(7)->getFrameOrigine()->position();
  butTenta2=joints.at(13)->getFrameOrigine()->position();
  butTenta3=joints.at(19)->getFrameOrigine()->position();
  butTenta4=joints.at(25)->getFrameOrigine()->position();
  butTenta5=joints.at(31)->getFrameOrigine()->position();
}

void Viewer::draw()
{
    if(cpt++ % 20==0){
        random=qrand()%6;
    }
    glBindTexture(GL_TEXTURE_2D, texture[random]);
    projet->draw();

   /* glPointSize(6.0);
    glColor3f(1.0, 0, 0);
    glBegin(GL_POINTS);
        for(int it=0; it<joints.size(); it++)
        {
            glVertex3fv((joints.at(it))->getFrameCourant()->position());
        }
        glColor3f(0.0, 0.0, 1.0);
        glVertex3fv(butTenta1);
        glVertex3fv(butTenta2);
        glVertex3fv(butTenta3);
        glVertex3fv(butTenta4);
        glVertex3fv(butTenta5);
    glEnd();
    glColor3f(0, 1.0, 0);
    glBegin(GL_LINE_STRIP);
       //bassin-tete
       glVertex3fv((joints.at(0))->getFrameCourant()->position());
       glVertex3fv((joints.at(1))->getFrameCourant()->position());
    glEnd();
    glBegin(GL_LINE_STRIP);
       //bassin_tenta1
       glVertex3fv((joints.at(0))->getFrameCourant()->position());
       glVertex3fv((joints.at(2))->getFrameCourant()->position());
       glVertex3fv((joints.at(3))->getFrameCourant()->position());
       glVertex3fv((joints.at(4))->getFrameCourant()->position());
       glVertex3fv((joints.at(5))->getFrameCourant()->position());
       glVertex3fv((joints.at(6))->getFrameCourant()->position());
       glVertex3fv((joints.at(7))->getFrameCourant()->position());
     glEnd();
     glBegin(GL_LINE_STRIP);
       //bassin_tenta2
       glVertex3fv((joints.at(0))->getFrameCourant()->position());
       glVertex3fv((joints.at(8))->getFrameCourant()->position());
       glVertex3fv((joints.at(9))->getFrameCourant()->position());
       glVertex3fv((joints.at(10))->getFrameCourant()->position());
       glVertex3fv((joints.at(11))->getFrameCourant()->position());
       glVertex3fv((joints.at(12))->getFrameCourant()->position());
       glVertex3fv((joints.at(13))->getFrameCourant()->position());
     glEnd();
     glBegin(GL_LINE_STRIP);
       //bassin_tenta3
       glVertex3fv((joints.at(0))->getFrameCourant()->position());
       glVertex3fv((joints.at(14))->getFrameCourant()->position());
       glVertex3fv((joints.at(15))->getFrameCourant()->position());
       glVertex3fv((joints.at(16))->getFrameCourant()->position());
       glVertex3fv((joints.at(17))->getFrameCourant()->position());
       glVertex3fv((joints.at(18))->getFrameCourant()->position());
       glVertex3fv((joints.at(19))->getFrameCourant()->position());
    glEnd();
    glBegin(GL_LINE_STRIP);
       //bassin_tenta4
       glVertex3fv((joints.at(0))->getFrameCourant()->position());
       glVertex3fv((joints.at(20))->getFrameCourant()->position());
       glVertex3fv((joints.at(21))->getFrameCourant()->position());
       glVertex3fv((joints.at(22))->getFrameCourant()->position());
       glVertex3fv((joints.at(23))->getFrameCourant()->position());
       glVertex3fv((joints.at(24))->getFrameCourant()->position());
       glVertex3fv((joints.at(25))->getFrameCourant()->position());
    glEnd();
    glBegin(GL_LINE_STRIP);
       //bassin_tenta5
       glVertex3fv((joints.at(0))->getFrameCourant()->position());
       glVertex3fv((joints.at(26))->getFrameCourant()->position());
       glVertex3fv((joints.at(27))->getFrameCourant()->position());
       glVertex3fv((joints.at(28))->getFrameCourant()->position());
       glVertex3fv((joints.at(29))->getFrameCourant()->position());
       glVertex3fv((joints.at(30))->getFrameCourant()->position());
       glVertex3fv((joints.at(31))->getFrameCourant()->position());
    glEnd();*/
}

void Viewer::animate()
{
     if(cpt++ % 40==0){
         projet->animate();
             for(int i=6; i>=1; i--){
                 //cinematic inverse tenta1
                 inv_kinematic.computeSinglePosition(joints, i, butTenta1);
                 //cinematic inverse tenta2
                 inv_kinematic.computeSinglePosition(joints, i+(6*1), butTenta2);
                 inv_kinematic.computeSinglePosition(joints, i+(6*2), butTenta3);
                 inv_kinematic.computeSinglePosition(joints, i+(6*3), butTenta4);
                 inv_kinematic.computeSinglePosition(joints, i+(6*4), butTenta5);
             }
             updateGL();
     }
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

    for(int i=0; i<listVertex.size(); i++){
        posVertexCourant.setValue(0, 0, 0);
        for(int j=0; j<jointure.size(); j++){
            Vec temp;
            temp.setValue(0, 0, 0);
            temp=jointure.at(j)->getFrameOrigine()->coordinatesOf(listOrigine.at(i).convertionVertex());
            temp=jointure.at(j)->getFrameCourant()->inverseCoordinatesOf(temp);
            posVertexCourant+=temp*listVertex.at(i).PoidJoint(j);
        }
        listVertex.at(i).setX(posVertexCourant.x);
        listVertex.at(i).setY(posVertexCourant.y);
        listVertex.at(i).setZ(posVertexCourant.z);
    }
}

/**
 * Chargement de la texture
 * @brief Projet::loadTexture
 * @param filename
 * @param width
 * @param height
 * @return
 */

void Projet::loadTexture(GLuint texture, QString filename){
    QImage image(filename, "JPG");
    QImage img=QGLWidget::convertToGLFormat(image);
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, texture);
    glTexImage2D (GL_TEXTURE_2D, 0, GL_RGB, img.width(), img.height(), 0, GL_RGBA, GL_UNSIGNED_BYTE, img.bits());
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
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
