#ifndef VERIFICATION_H
#define VERIFICATION_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Enums.h"

class Verification
{
public:
	const char * msg;
	const char * encodedMessage;
	char temp[51];

	Enums::ClassType clsType;
	Enums::MessageType msgType;

	Verification(const char[], Enums::ClassType, Enums::MessageType);
	Verification(char[]);
	void Encode();
	void Decode();
};
#endif
