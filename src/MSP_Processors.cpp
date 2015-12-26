/*
  MSP - Library for MultiWii Serial Protocol
  Created by Filip Prochazka (jacktech24), 2015.
  Released under GNUGPLv3 license.
*/

#include "MSP_Processors.h"
#include "MSP_Data.h"

void MSP_Processors::process_Ident(uint8_t payloadSize, uint8_t *payload, MSP_Ident callback) {
    if(payloadSize == 8) {
        uint8_t version = (uint8_t) payload[0];
        uint8_t multiType = (uint8_t) payload[1];
        uint8_t mspVersion = (uint8_t) payload[2]; //not used
        uint32_t capability = (uint32_t) payload[4] << 24;
        capability |= (uint32_t) payload[5] << 16;
        capability |= (uint32_t) payload[6] << 8;
        capability |= (uint32_t) payload[7];

        if (callback) {
            callback(version, multiType, mspVersion, capability);
        }
    }
}

void MSP_Processors::process_Status(uint8_t payloadSize, uint8_t *payload, MSP_Status callback) {
    if(payloadSize == 11) {
        uint16_t cycleTime = (uint16_t) payload[0] << 8;
        cycleTime |= (uint16_t) payload[1];
        uint16_t i2cErrorsCount = (uint16_t) payload[2] << 8;
        i2cErrorsCount |= (uint16_t) payload[3];
        uint16_t sensors = (uint16_t) payload[4] << 8;
        sensors |= (uint16_t) payload[5];
        uint32_t flag = (uint32_t) payload[6] << 24;
        flag |= (uint32_t) payload[7] << 16;
        flag |= (uint32_t) payload[8] << 8;
        flag |= (uint32_t) payload[9];
        uint8_t profile = payload[10];

        if(callback) {
            callback(cycleTime, i2cErrorsCount, sensors, flag, profile);
        }
    }
}