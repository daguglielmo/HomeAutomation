#include "MyMqtt.h"
int main(int argc, char *argv[])
{
	class MyMqtt *mqtt;	// Declare MyMqtt class
	int rc;	// Used for deternining if a reconnection is required

	mosqpp::lib_init();	// Required before any mosquittopp commands can be issued

	mqtt = new MyMqtt("Hub", "10.0.0.105", 1883);	// Instantiate instance of MyMqtt and declare id, ip address of Broker and port

	while(1){
		rc = mqtt->loop();	// Set rc to be the return value of the mosquitto_loop
		if(rc)	// Determine if reconnection required
		{
			mqtt->reconnect();	// Forces reconnection
		}
	}
	mosqpp::lib_cleanup();	// Releases mosquitopp resources

	return 0;
}
