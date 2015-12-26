/*
  MSP - Library for MultiWii Serial Protocol
  Created by Filip Prochazka (jacktech24), 2015.
  Released under GNUGPLv3 license.
*/

#ifndef MSP_H
#define MSP_H

#include "Arduino.h"
#include "MSP_Constants.h"
#include "MSP_Data.h"

class MSP_Callbacks {
public:
    MSP_Callbacks() { }

    MSP_Ident onIdent;
    MSP_Status onStatus;
    MSP_SensorValues onSensorValues;
    MSP_ServoData onServoData;
    MSP_MotorData onMotorData;
    MSP_GPSRawData onGPSRawData;
    MSP_GPSComputedData onGPSComputedData;
    MSP_Attitude onAttitude;
    MSP_Altitude onAltitude;
    MSP_Sonar onSonar;
    MSP_Analog onAnalog;
    MSP_PID onPID;
    MSP_ArmingConfig onArmingConfig;
    MSP_LoopTime onLoopTime;
    MSP_Misc onMisc;
};

class MSP {

public:
    MSP(HardwareSerial *communicationStream);

    void loop();

    void begin();

private:
    HardwareSerial *_serial;
    MSP_Callbacks _mspCallbacks;

    void processInputMsg();

    uint8_t *readMsgDataPart(uint8_t payloadLength);

    void sendMsgRequest(MSP_Messages messages);

    MSP_Callbacks *getCallbacks();

    uint8_t *_payload;
};

#endif //MSP_H