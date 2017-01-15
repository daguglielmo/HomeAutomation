#ifndef __ENUMS_H__
#define __ENUMS_H__

class Enums
{
public:
        Enums();
        enum ClassType
        {
                THERMOSTAT = 0, // Main Thermostat
                DOOR = 1,               // Door status detector
                GARAGEDOOR = 2  // Garage door status and open close commands
        };
        enum MessageType
        {
                REP = 0, // Reporting - Report Current Status
                COM = 1,      // Command - Issue a command
                VER = 2       // Verify - Getting the type of node
        };
};
#endif
