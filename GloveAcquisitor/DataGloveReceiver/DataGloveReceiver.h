
/**
*		Class DataGloveReceiver
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
*	La réception et le dépaquetage de ces données, en étant à l'écoute sur le port UDP indiqué lors
*	de l'instanciation de l'objet (default : #4242)
*/

#if defined (WIN32)

// Network Windows
#include <winsock2.h>
#include <Ws2tcpip.h>
#pragma comment(lib,"ws2_32.lib") //Winsock Library

typedef int socklen_t;

#else

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define INVALID_SOCKET -1
#define SOCKET_ERROR -1
#define closesocket(s) close (s)

typedef int SOCKET;
typedef struct sockaddr_in SOCKADDR_IN;
typedef struct sockaddr SOCKADDR;

#endif

// STL
#include <vector>
#include <map> 
#include <utility>

// Common
#include <iostream>
#include <fstream>
#include <string> 
#include <cstring>

using namespace std;

enum Finger {

	THUMB = 0,
	INDEX = 1,
	MIDDLE = 2,
	RING = 3,
	PINKY = 4
};

class DataGloveReceiver {

public:

	DataGloveReceiver(int port = 4242);

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
	*	Affichage sur la sortie standard
	*/
	void print();

	/*
	*	Attend l'arrivée d'un paquet UDP sur le port défini (bloquant)
	*	Lorsqu'un paquet arrive, il est désérialisé, et inséré dans model(STL)
	*/
	void receive();

private:

	/// SERIALISATION

	/*
	*	Sérialise un nombre de type double dans un buffer
	*	d --> 010101... --> buffer
	*	@param d : double à convertir
	*/
	inline void toBytes(double d) {
		std::memcpy(&buffer, &d, sizeof(double));
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

	#if defined (WIN32)
		WSADATA wsaData;
	#endif

	SOCKET RecvSocket = INVALID_SOCKET;
	sockaddr_in RecvAddr;
	socklen_t Recvsize = ((unsigned int) sizeof(RecvAddr));

	int port_in = 4242;

	//int SenderAddrSize = ((unsigned int) sizeof(RecvAddr));

	void initSocket(int port);

};
