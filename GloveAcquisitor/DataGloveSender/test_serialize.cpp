#include <iostream>
#include <algorithm>
#include <random>
#include <vector>
#include <stdlib.h>

#include "DataGloveSender.h"

using namespace std;

std::vector<double> gen_random_vec() {

	std::vector<double> v;

	double lower_bound = 0;
	double upper_bound = 1000;
	std::uniform_real_distribution<double> unif(lower_bound, upper_bound);
	std::default_random_engine re;

	for (int i = 0; i < 30; i++) {
		double d = unif(re);
		v.push_back(d);
	}

	return v;
}

double gen_random() {

	double lower_bound = 0;
	double upper_bound = 1000;
	std::uniform_real_distribution<double> unif(lower_bound, upper_bound);
	std::default_random_engine re;
	double d = unif(re);

	return d;
}

int main() {

	std::cout << endl;

	std::cout << "#####################" << endl;
	std::cout << " Test Serialization  " << endl;
	std::cout << "#####################" << endl;

	DataGloveSender data;

	cout << endl << "Let be the following data set : " << endl;

	std::vector<double> values = gen_random_vec();

	
	//sleep(0.04);
	for (int i = 0; i < values.size(); ++i) {
		data.setData(i, values.at(i));
	}

	data.print();

	cout << endl << "-- Serialization... --" << endl;

	data.send();

	cout << "Datagram sent ! :)" << endl;

	system("pause");

}