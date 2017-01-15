#include "Verification.h"

const char * msg;
const char * encodedMessage;
Enums::ClassType clsType;
Enums::MessageType msgType;

Verification::Verification(const char _msg[], Enums::ClassType _clsType, Enums::MessageType _msgType)
{
	clsType = _clsType;
        msgType = _msgType;
        msg = _msg;
}
Verification::Verification(const char _encodedMessage[])
{
	encodedMessage = _encodedMessage;
}
void Verification::Encode()
{
	char temp[51];
	sprintf(temp,"%d:%d:%s",clsType,msgType,msg);
	encodedMessage = temp;

}
void Verification::Decode()
{
	
}
