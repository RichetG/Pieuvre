receiver : DataGloveReceiver_Network.o DataGloveReceiver_Serialization.o  test_deserialize.o
	g++ -o receiver DataGloveReceiver_Network.o DataGloveReceiver_Serialization.o test_deserialize.o

test_deserialize.o : test_deserialize.cpp
	g++ -c test_deserialize.cpp

DataGloveReceiver_Network.o : DataGloveReceiver.h DataGloveReceiver_Network.cpp
	g++ -c DataGloveReceiver.h DataGloveReceiver_Network.cpp

DataGloveReceiver_Serialization.o : DataGloveReceiver.h DataGloveReceiver_Network.cpp
	g++ -c DataGloveReceiver.h DataGloveReceiver_Serialization.cpp