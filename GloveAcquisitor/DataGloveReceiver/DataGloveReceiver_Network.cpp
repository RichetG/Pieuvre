#include "DataGloveReceiver.h"
#include <cstdlib>

// references : 
//	http://msdn.microsoft.com
//	https://msdn.microsoft.com/en-us/library/windows/desktop/ms741394(v=vs.85).aspx

using namespace std;

void DataGloveReceiver::initSocket(int port) {

	#if defined (WIN32)
		//-----------------------------------------------
		// Initialize Winsock

		iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
		if (iResult != NO_ERROR) {
			wprintf(L"WSAStartup failed with error %d\n", iResult);
			exit(1);
		}
	#endif

	//-----------------------------------------------
	// Create a receiver socket to receive datagrams
	RecvSocket = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
	if (RecvSocket == INVALID_SOCKET) {
		//wprintf(L"socket failed with error %d\n", WSAGetLastError());
		std::cout << "Unable to create socket" << endl ;
		exit(1);
	}
	//-----------------------------------------------
	// Bind the socket to any address and the specified port.
	RecvAddr.sin_family = AF_INET;
	RecvAddr.sin_port = htons(port);
	RecvAddr.sin_addr.s_addr = htonl(INADDR_ANY);

	iResult = bind(RecvSocket, (SOCKADDR *)& RecvAddr, Recvsize);
	if (iResult != 0) {
		//wprintf(L"bind failed with error %d\n", WSAGetLastError());
		std::cout << "Unable to bind socket" << endl ;
		exit(1);
	}

	std::cout << endl << "Socket OK" << endl;
}

void DataGloveReceiver::receive() {

	std::cout << endl << "Listening on localhost:" << port_in << "..." << endl;
	int iResult = recvfrom(RecvSocket,
		model_bytes, sizeof(model_bytes), 0, (SOCKADDR *)& RecvAddr, &Recvsize);
	if (iResult == SOCKET_ERROR) {
		//std::cout << "Failed ! Error : " << WSAGetLastError();
		std::cout << "Error ! :'(" << endl ;
	}
	std::cout << "Datagram received !" << endl;
	std::cout << endl << "-- Deserialization... --" << endl;
	this->deserialize();
}
