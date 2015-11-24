#include <iostream>
#include "DataGloveReceiver.h"

using namespace std;

int main() {

	std::cout << endl;

	std::cout << "#####################" << endl;
	std::cout << " Test De-Serialization " << endl;
	std::cout << "#####################" << endl;

	DataGloveReceiver data;

	while (1) {
		data.receive();
		data.print();
	}
}