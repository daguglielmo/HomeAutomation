#include <cstdio>
#include <cstring>

#include "MyMqtt.h"
#include </usr/include/mosquittopp.h>

MyMqtt::MyMqtt(const char *id, const char *host, int port) : mosquittopp(id)
{
	int keepalive = 60;
	connect(host, port, keepalive);
}

MyMqtt::~MyMqtt()
{
}

void MyMqtt::on_connect(int rc)
{
	printf("Connected with code %d.\n", rc);
	if(rc == 0)
	{
                /* Only attempt to subscribe on a successful connect. */
                subscribe(NULL, "Hub/#");
	}
}

void MyMqtt::on_message(const struct mosquitto_message *message)
{
/*        double temp_celsius, temp_farenheit;
        char buf[51];

        if(!strcmp(message->topic, "Thermostat/Change/TempUp")){
                memset(buf, 0, 51*sizeof(char));
                /* Copy N-1 bytes to ensure always 0 terminated. /
                memcpy(buf, message->payload, 50*sizeof(char));
                temp_celsius = atof(buf);
                temp_farenheit = temp_celsius*9.0/5.0 + 32.0;
                snprintf(buf, 50, "%f", temp_farenheit);
                publish(NULL, "temperature/farenheit", strlen(buf), buf);*/
	char* topic = (char*)message->topic;
	char* payload = (char*)message->payload;
	printf("Topic: %s\n", topic);
	printf("Message: %s\n", payload);
}

void  MyMqtt::on_subscribe(int mid, int qos_count, const int *granted_qos)
{
	printf("Subscription succeeded.\n");
}
