#include <cstdio>
#include <cstring>

#include "MyMqtt.h"
#include </usr/include/mosquittopp.h>

MyMqtt::MyMqtt(const char *id, const char *host, int port) : mosquittopp(id)
{
	int keepalive = 60;
	connect(host, port, keepalive);	// Connect to designated broker and set keep alive
}

MyMqtt::~MyMqtt()
{
}

void MyMqtt::on_connect(int rc)
{
	printf("Connected with code %d.\n", rc);	// Prints connection code. Should be 0
}

void MyMqtt::on_message(const struct mosquitto_message *message)
{
	char* topic = (char*)message->topic;	// Assign topic to char pointer for display
	char* payload = (char*)message->payload;	// Assign payload to char pointer for display
	printf("Topic: %s\n", topic);	// Display topic
	printf("Message: %s\n", payload);	// Display payload
}

void  MyMqtt::on_subscribe(int mid, int qos_count, const int *granted_qos)
{
	printf("Subscription succeeded.\n");	// Print on sucessful subscription
}
