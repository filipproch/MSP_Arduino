/*
  MSP - Library for MultiWii Serial Protocol
  Created by Filip Prochazka (jacktech24), 2015.
  Released under GNUGPLv3 license.
*/

#ifndef MSP_PROCESSORS_H
#define MSP_PROCESSORS_H

#include "MSP_Data.h"

class MSP_Processors {
public:
    static void process_Ident(uint8_t payloadSize, uint8_t *payload, MSP_Ident callback);
    static void process_Status(uint8_t payloadSize, uint8_t *payload, MSP_Status callback);
};


#endif //MSP_PROCESSORS_H
