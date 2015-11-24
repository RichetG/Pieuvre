
#include "DataGloveSender.h"

using namespace std;

/// PUBLIC

DataGloveSender::DataGloveSender() {

	// init data structure
	vector<double> v(3, 0.0);
	for (int i = 0; i < 5; i++) {
		Finger finger = static_cast<Finger>(i);

		this->setPosition(finger, v);
		this->setNormal(finger, v);
	}

	// init socket

	this->initSocket();
}

void DataGloveSender::setPosition(Finger finger, vector<double> position) {

	model[finger].first = position;
}

void DataGloveSender::setPosition(Finger finger, double x, double y, double z) {

	pos.clear();
	pos.push_back(x);
	pos.push_back(y);
	pos.push_back(z);
	DataGloveSender::setPosition(finger, pos);
}

void DataGloveSender::setNormal(Finger finger, vector<double> normal) {

	model[finger].second = normal;
}

void DataGloveSender::setNormal(Finger finger, double x, double y, double z) {

	nor.clear();
	nor.push_back(x);
	nor.push_back(y);
	nor.push_back(z);
	DataGloveSender::setNormal(finger, nor);
}

vector<double> DataGloveSender::getPosition(Finger finger) {

	return model[finger].first;
}

vector<double> DataGloveSender::getNormal(Finger finger) {

	return model[finger].second;
}

double DataGloveSender::getData(int i) {

	Finger finger = static_cast<Finger>(i / 6);
	int op = i % 6;
	vector<double> v = (op < 3) ? getPosition(finger) : getNormal(finger);

	switch (op) {

		case 0: case 3: {
			return v.at(0);
			break;
		}
		case 1: case 4: {
			return v.at(1);
			break;
		}
		case 2: case 5: {
			return v.at(2);
			break;
		}

		default: {
			return 1;
			break;
		}
	}
}

void DataGloveSender::setData(int i, double d) {

	Finger finger = static_cast<Finger>(i / 6);
	int op = i % 6;
	//cout << "finger : " << finger << ", op : " << op << endl ; 
	vector<double> v = (op < 3) ? this->getPosition(finger) : this->getNormal(finger);
	//cout << "vector : " << v.size() << " " << v.at(0) << " " << v.at(1) << " " << v.at(2) << endl ;

	switch (op) {

		case 0: case 3: {
			v.at(0) = d;
			break;
		}
		case 1: case 4: {
			v.at(1) = d;
			break;
		}
		case 2: case 5: {
			v.at(2) = d;
			break;
		}

		default: {
			break;
		}
	}

	if (op < 3) this->setPosition(finger, v);
	else this->setNormal(finger, v);

	//cout << "Data[ " << i << " ] : " << d << endl ;
}



void DataGloveSender::print() {

	for (int i = 0; i < 5; ++i) {
		Finger finger = static_cast<Finger>(i);
		std::cout << "_________________________________________" << endl;
		std::cout << "Finger #" << finger << endl << endl;
		vector<double> v = this->getPosition(finger);
		std::cout << "Position : [ " << v.at(0) << ", " << v.at(1) << ", " << v.at(2) << " ]" << endl;
		v = this->getNormal(finger);
		std::cout << "Normal : [ " << v.at(0) << ", " << v.at(1) << ", " << v.at(2) << " ]" << endl;
		std::cout << "_________________________________________" << endl;
	}
}

/// PRIVATE

void DataGloveSender::serialize() {

	int offset = 0;

	for (int i = 0; i < 30; i++) {
		double d = getData(i);
		DataGloveSender::toBytes(d);

		for (int n = 0; n < sizeof(double); n++) {
			model_bytes[n + offset] = buffer[n];
		}
		offset += 8;
	}
	std::cout << "Finished : buffer[ :  " << model_bytes << " ]" << endl;
}

void DataGloveSender::deserialize() {

	int offset = 0;

	for (int i = 0; i < 30; i++) {

		for (int n = 0; n < sizeof(double); n++) {
			buffer[n] = model_bytes[n + offset];
		}
		double d = toDouble();
		setData(i, d);
		offset += 8;
	}
}