#pragma once

/**
 *		Class DataGloveSender
 *	=============================
 *
 *	Encapsule une description du syst�me � un instant t.
 *	
 *	A chaque doigt est associ� : 
 *		- un vector<double> position
 *		- un vector<double> normals
 *
 *	Ces donn�es sont accessibles en lecture/�criture via les fonctions get/set �ponymes
 *
 *	Permet le paquetage et l'envoi de ces donn�es � travers un datagramme UDP de 240 octets
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
	 *	Acc�s du vecteur position associ� � un doigt
	 *	@param finger : doigt
	 */
	vector<double> getPosition(Finger finger);

	/*
	*	Acc�s du vecteur normal associ� � un doigt
	*	@param finger : doigt
	*/
	vector<double> getNormal(Finger finger);

	/*  Acc�s par index
	 *	ordre : position[THUMB], normals[THUMB], position[INDEX], ... , normals[PINKY]
	 */
	void setData(int index, double value);

	/*  Acc�s par index
	*	ordre : position[THUMB], normals[THUMB], position[INDEX], ... , normals[PINKY]
	*/
	double getData(int index);

	/*
	 * D�finit le r�cepteur des datagrammes
	 * @param host : ip/nom de l'hote de destination
	 * @param port : numero de port UDP
	 */
	void target(char* host, int port);

	/*
	 *	Affichage sur la sortie standard
	 */
	void print();

	/*
	 *	S�rialise le mod�le courant 
	 *	l'envoie dans un datagramme UDP � la destination d�finie par la fontion target
	 */
	void send();

private:

		/// SERIALISATION

	/*
	 *	S�rialise un nombre de type double dans un buffer
	 *	d --> 010101... --> buffer
	 *	@param d : double � convertir
	 */
	inline void toBytes(double d) {
		memcpy(&buffer, &d, sizeof(double));
	}

	/*
	 *	Retourne l'interpr�tation du contenu actuel de buffer en nombre double
	 *  return double
	 */
	inline double toDouble() {
		return *((double *)buffer);
	}

	/*
	 *	S�rialise toutes les donn�es contenues dans model (STL)
	 *	et les stocke � la suite dans model_bytes
	 */
	void serialize();

	/*
	 *	Stocke dans model(STL) l'interpr�tation du contenu actuel de model_bytes
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