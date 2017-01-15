#ifndef VERIFICATION_H
#define VERIFICATION_H

#include <stdio.h>
//#include <string.h>
//#include <sstream>
//#include <vector>
#include "Enums.h"

class Verification
{
public:
	const char * msg;
	const char * encodedMessage;
	Enums::ClassType clsType;
	Enums::MessageType msgType;

	Verification(const char[], Enums::ClassType, Enums::MessageType);
	Verification(const char[]);
	void Encode();
	void Decode();
//        void Split(const std::string, char, std::vector<std::string>);
//        void Split(const std::string, char);
};
#endif
