//Verification.cpp

#include "Verification.h"
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
char msg;
char encodedMessage;
char temp[51]= {'0'}; //used to hold value
Enums::ClassType clsType;
Enums::MessageType msgType;

/* Instantiate Verification class with data seperated into RF24 broken up instances */
Verification::Verification(const char _msg[], Enums::ClassType _clsType, Enums::MessageType _msgType)
{
        clsType = _clsType;
        msgType = _msgType;
        msg = _msg;
        Encode();
}

/* Instantiate Verification class with MQTT transmittable message string*/
Verification::Verification(char _encodedMessage[])
{
        encodedMessage = _encodedMessage;
        Decode();
}

/* Construct MQTT transmittable message from RF24 parts */
void Verification::Encode()
{
        sprintf(temp, "%d:%d:%s", static_cast<int>(clsType), static_cast<int>(msgType), msg);
        encodedMessage = temp;
}

/* Construct RF24 parts from MQTT transmitted messages*/
void Verification::Decode()
{
        char* _encodedMsg = strdup(encodedMessage);
        char* charArrays[3];

        unsigned int index = 0;
        charArrays[index] = strtok(_encodedMsg, ":");
        while (charArrays[index] != NULL)
        {
                ++index;
                charArrays[index] = strtok(NULL,":");
        }
        int clsInt = atoi(charArrays[0]);
        int msgInt = atoi(charArrays[1]);
        clsType = static_cast<Enums::ClassType>(clsInt);
        msgType = static_cast<Enums::MessageType>(msgInt);
        msg = charArrays[2];
}

