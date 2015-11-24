#include "face.h"
#include <sstream>

/**
 * Constructeur Face
 * @brief Face::Face
 */
Face::Face(){
    listTriplets.clear();
}

/**
 * Ajout des triplets vertex/texture/normale
 * @brief Face::add
 * @param triplet
 */
void Face::add(TripletFace triplet){
    listTriplets.push_back(triplet);
}

/**
 * Retrait des triplets vertex/texture/normale
 * @brief Face::remove
 * @param triplet
 */
void Face::remove(TripletFace triplet){
    vector<TripletFace>tmp;
    for(int i=0; i<listTriplets.size(); i++){
        if(listTriplets.at(i).print().compare(triplet.print())!=0){
            tmp.push_back(listTriplets.at(i));
        }
        listTriplets.clear();
        listTriplets=tmp;
    }
}

/**
 * Récupération contenue face
 * @brief at
 * @param index
 * @return list triplet
 */
TripletFace Face::at(int index){
    return listTriplets.at(index);
}

/**
 * Taille de la list triplet
 * @brief size
 * @return taille list triplet
 */
int Face::size(){
    return listTriplets.size();
}

/**
 * Impression d'une face "f v1/t1/n1 v2/t2/n2 v3/t3/n3"
 * @brief Face::print
 * @return une face au format obj
 */
string Face::print(){
    stringstream ligneF;
    string ligne="f ";
    for(int i=0; i<listTriplets.size(); i++){
        ligne+=listTriplets.at(i).print()+" ";
    }
    ligneF<<ligne;
    return ligneF.str();
}
