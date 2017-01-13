#ifndef VERIFICATION_H
#define VERIFICATION_H

#include <string>
#include "Enums.h"
class Verification
{
public:
        Verification(std::string, Enums::ClassType);
        std::string id;
        Enums::ClassType type;
};
#endif
