#ifndef RF24MESHNET_H
#define RF24MESHNET_H
// Mesh.h
#include </usr/local/include/RF24/RF24.h>
#include </usr/local/include/RF24Network/RF24Network.h>
#include "/usr/local/include/RF24Mesh/RF24Mesh.h"

class MeshNet
{
public:
//	RF24::RF24 radio;//(22,0);
//	RF24Network::RF24Network network;//(radio);
//	RF24Mesh::RF24Mesh mesh;//(radio,network);
	MeshNet(int val);
//	~MeshNet();
//	RF24 radio;//(22,0);
//	RF24Network network;//(radio);
//	RF24Mesh mesh;//(radio,network);
	
	void Setup(int val);
	bool Write(const void * message, char messageType, int node = 0);
};
#endif
