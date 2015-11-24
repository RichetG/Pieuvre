#pragma once

/**
 *		Class DataGloveSender
 *	=============================
 *
 *	Encapsule une description du système à un instant t.
 *	
 *	A chaque doigt est associé : 
 *		- un vector<double> position
 *		- un vector<double> normals
 *
 *	Ces données sont accessibles en lecture/écriture via les fonctions get/set éponymes
 *
 *	Permet le paquetage et l'envoi de ces données à travers un datagramme UDP de 240 octets
 */

// Network Windows
#include <winsock2.h>
#include <Ws2tcpip.h>
#pragma comment(lib,"ws2_32.lib") //Winsock Library

// STL
#include <vector>
#include <map> 
#include <utility>

// Common
#include <iostream>
#include <fstream>
#include <string> 

using namespace std;

enum Finger {

	THUMB = 0,
	INDEX = 1,
	MIDDLE = 2,
	RING = 3,
	PINKY = 4
};

class DataGloveSender {

public:

	DataGloveSender();

	void setPosition(Finger finger, vector<double> pos);

	void setPosition(Finger finger, double x, double y, double z);

	void setNormal(Finger finger, vector<double> norm);

	void setNormal(Finger finger, double x, double y, double z);

	/*
	 *	Accès du vecteur position associé à un doigt
	 *	@param finger : doigt
	 */
	vector<double> getPosition(Finger finger);

	/*
	*	Accès du vecteur normal associé à un doigt
	*	@param finger : doigt
	*/
	vector<double> getNormal(Finger finger);

	/*  Accès par index
	 *	ordre : position[THUMB], normals[THUMB], position[INDEX], ... , normals[PINKY]
	 */
	void setData(int index, double value);

	/*  Accès par index
	*	ordre : position[THUMB], normals[THUMB], position[INDEX], ... , normals[PINKY]
	*/
	double getData(int index);

	/*
	 * Définit le récepteur des datagrammes
	 * @param host : ip/nom de l'hote de destination
	 * @param port : numero de port UDP
	 */
	void target(char* host, int port);

	/*
	 *	Affichage sur la sortie standard
	 */
	void print();

	/*
	 *	Sérialise le modèle courant 
	 *	l'envoie dans un datagramme UDP à la destination définie par la fontion target
	 */
	void send();

private:

		/// SERIALISATION

	/*
	 *	Sérialise un nombre de type double dans un buffer
	 *	d --> 010101... --> buffer
	 *	@param d : double à convertir
	 */
	inline void toBytes(double d) {
		memcpy(&buffer, &d, sizeof(double));
	}

	/*
	 *	Retourne l'interprétation du contenu actuel de buffer en nombre double
	 *  return double
	 */
	inline double toDouble() {
		return *((double *)buffer);
	}

	/*
	 *	Sérialise toutes les données contenues dans model (STL)
	 *	et les stocke à la suite dans model_bytes
	 */
	void serialize();

	/*
	 *	Stocke dans model(STL) l'interprétation du contenu actuel de model_bytes
	 */
	void deserialize();

	// repetitive iterators
	vector<double> pos;
	vector<double> nor;
	char buffer[sizeof(double)];

	// Bytes version
	char model_bytes[5 * 2 * 3 * sizeof(double)]; // 240 bytes
	const int BUFFER_LENGTH = 5 * 2 * 3 * sizeof(double);

	// STL Object Version
	map<Finger, pair<vector<double>, vector<double> > > model;

		/// NETWORK

	int iResult = 0;

	WSADATA wsaData;

	SOCKET SendSocket = INVALID_SOCKET;
	sockaddr_in SndAddr;
	int SenderAddrSize = sizeof(SndAddr);

	int port = 4242;
	char* host = "localhost";

	void initSocket();

};