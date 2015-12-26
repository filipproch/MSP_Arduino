/*
  MSP - Library for MultiWii Serial Protocol
  Created by Filip Prochazka (jacktech24), 2015.
  Released under GNUGPLv3 license.
*/

#include "Arduino.h"
#include "MSP.h"
#include "MSP_Data.h"
#include "MSP_Processors.h"

MSP::MSP(HardwareSerial *communicationStream) {
    _serial = communicationStream;
    _serial->begin(115200);
}

void MSP::begin() {
    MSP::sendMsgRequest(MSP_MSG_IDENT);
}

void MSP::loop() {
    while (_serial->available()) {
        uint8_t inVal = (uint8_t) _serial->read();
        if (inVal == MSP_PREAMBLE_PART1) { //possible start of message
            inVal = (uint8_t) _serial->read();
            if (inVal == MSP_PREAMBLE_PART2) { //confirmation with second byte
                MSP::processInputMsg();
            }
        }
    }
}

void MSP::processInputMsg() {
    uint8_t direction = (uint8_t) _serial->read();
    uint8_t payloadLength = (uint8_t) _serial->read();
    uint8_t msgId = (uint8_t) _serial->read();

    uint8_t *payload = MSP::readMsgDataPart(payloadLength);

    if (direction == MSP_DIRECTION_IN) {
        switch (msgId) {
            case MSP_MSG_IDENT:
                MSP_Processors::process_Ident(payloadLength, payload, getCallbacks()->onIdent);
                break;
            case MSP_MSG_STATUS:
                MSP_Processors::process_Status(payloadLength, payload, getCallbacks()->onStatus);
                break;
            default:
                //ignore, unknown or not important message
                break;
        }
    }
}

uint8_t *MSP::readMsgDataPart(uint8_t payloadLength) {
    _payload[payloadLength] = {};
    for(int i = 0;i < payloadLength;i++) {
        _payload[i] = (uint8_t) _serial->read();
    }
    return _payload;
}

void MSP::sendMsgRequest(MSP_Messages messages) {

}

MSP_Callbacks *MSP::getCallbacks() {
    return &_mspCallbacks;
}
