#include "MyMqtt.h"
int main(int argc, char *argv[])
{
	class MyMqtt *mqtt;
	int rc;

	mosqpp::lib_init();

	mqtt = new MyMqtt("Hub", "10.0.0.105", 1883);

	while(1){
		rc = mqtt->loop();
		if(rc)
		{
			mqtt->reconnect();
		}
	}
	mosqpp::lib_cleanup();

	return 0;
}
