#include "MyMqtt.h"
#include "Verification.h"

//Define global tokens
#define ID	"Hub"
#define BROKER	"10.0.0.105"
#define PORT	1883
#define LISTEN	"Hub/Incoming/#"


int main(int argc, char *argv[])
{
	class MyMqtt *mqtt;	// Declare MyMqtt class
	int rc;	// Used for deternining if a reconnection is required

	mosqpp::lib_init();	// Required before any mosquittopp commands can be issued

	mqtt = new MyMqtt(ID, BROKER, PORT);	// Instantiate instance of MyMqtt and declare id, ip address of Broker and port

	if(mqtt->loop() == 0)	//If mqtt Sucessfully connected to broker
	{
		mqtt->subscribe(NULL, LISTEN);	// Subscribe to all incoming hub messages
	}

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
