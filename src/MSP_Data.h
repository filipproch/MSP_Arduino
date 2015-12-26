/*
  MSP - Library for MultiWii Serial Protocol
  Created by Filip Prochazka (jacktech24), 2015.
  Released under GNUGPLv3 license.
*/

#ifndef MSP_DATA_H
#define MSP_DATA_H

#include "Arduino.h"

typedef void (*MSP_Ident)(float_t version, uint8_t multiType, uint8_t mspVersion, uint32_t capability);

typedef void (*MSP_Status)(uint16_t cycleTime, uint16_t i2cError, uint16_t activeSensors, uint32_t mode,
                           uint8_t profile);

typedef void (*MSP_SensorValues)(uint16_t accelerometer[3], uint16_t gyroscope[3], uint16_t magnetometer[3]);

typedef void (*MSP_ServoData)(uint8_t servoCount, uint16_t *servos);

typedef void (*MSP_MotorData)(uint8_t motorCount, uint16_t *motors);

typedef void (*MSP_GPSRawData)(uint8_t fix, uint8_t numSat, uint32_t lat, uint32_t lon, uint16_t alt,
                               uint16_t speed,
                               uint16_t groundCourse);

typedef void (*MSP_GPSComputedData)(uint16_t distanceToHome, uint16_t directionToHome, uint8_t update);

typedef void (*MSP_Attitude)(uint16_t *kinematics);

typedef void (*MSP_Altitude)(float_t altitude);

typedef void (*MSP_Sonar)(uint32_t sonar);

typedef void (*MSP_Analog)(float_t voltage, uint16_t mAhdrawn, uint16_t rssi, float_t amperage);

//todo: MSP_RCTuning

typedef void (*MSP_PID)();

typedef void (*MSP_ArmingConfig)(uint8_t autoDisarmDelay, uint8_t disarmKillSwitch);

typedef void (*MSP_LoopTime)(uint16_t loopTime);

typedef void (*MSP_Misc)();

#endif //MSP_DATA_H
