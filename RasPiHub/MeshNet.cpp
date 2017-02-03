// Mesh.cpp
#include "MeshNet.h"

RF24 radio(22,0);
RF24Network network(radio);
RF24Mesh mesh(radio,network);
MeshNet::MeshNet(int val)
{
	Setup(val);
}

void MeshNet::Setup(int val)
{
	// Set the nodeID to 0 for the master node
	mesh.setNodeID(val);
	// Connect to the mesh
	printf("start Mesh\n");
	mesh.begin();
	printf("started Mesh\n");
	radio.printDetails();
}
bool MeshNet::Write(const void * message, char messageType, int node)
{
	return mesh.write(&message, messageType, sizeof(message), node);
}
