#include "DataGloveSender.h"

// references : 
//	http://msdn.microsoft.com
//	https://msdn.microsoft.com/en-us/library/windows/desktop/ms741394(v=vs.85).aspx

void DataGloveSender::initSocket() {

	//-----------------------------------------------
	// Initialize Winsock
	iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
	if (iResult != NO_ERROR) {
		wprintf(L"WSAStartup failed with error %d\n", iResult);
		exit(1);
	}

	SendSocket = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);

	if (SendSocket == INVALID_SOCKET) {
		wprintf(L"socket failed with error: %ld\n", WSAGetLastError());
		WSACleanup();
		exit(1);
	}

	target("127.0.0.1", port); // default

	std::cout << endl << "Socket OK" << endl;
}

void DataGloveSender::target(char* host, int port) {

	//---------------------------------------------
	// Set up the RecvAddr structure with the IP address of
	// the receiver (in this example case "192.168.1.1")
	// and the specified port number.
	SndAddr.sin_family = AF_INET;
	SndAddr.sin_port = htons(port);
	SndAddr.sin_addr.s_addr = inet_addr(host);
	this -> host = host;
	this -> port = port;
}

void DataGloveSender::send() {

	this->serialize();

	//---------------------------------------------
	// Send a datagram to the receiver
	std::cout << "Sending datagram to " << this -> host << ":" << this -> port << endl;
	iResult = sendto(SendSocket,
		model_bytes, BUFFER_LENGTH, 0, (SOCKADDR *)& SndAddr, sizeof(SndAddr));
	if (iResult == SOCKET_ERROR) {
		std::cout << "Failed ! Error : " << WSAGetLastError();
		closesocket(SendSocket);
		WSACleanup();
		exit(1);
	}
}
