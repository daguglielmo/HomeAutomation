#ifndef MYMQTT_H
#define MYMQTT_H

#include </usr/include/mosquittopp.h>

class MyMqtt : public mosqpp::mosquittopp
{
        public:
                MyMqtt(const char *id, const char *host, int port);
                ~MyMqtt();

                void on_connect(int rc);
                void on_message(const struct mosquitto_message *message);
                void on_subscribe(int mid, int qos_count, const int *granted_qos);
};

#endif
