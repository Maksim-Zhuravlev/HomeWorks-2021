#ifndef UNTITLED_PAYLOAD_H
#define UNTITLED_PAYLOAD_H


#define MAX_WORD_LENGTH 128

#include <wchar.h>

typedef int valueType;
typedef char keyType[MAX_WORD_LENGTH + 1];


struct Payload {
    keyType key;
    valueType value;
};


void printPayload(struct Payload data);

_Bool compareKeys(keyType key1, keyType key2);

void setPayloadKey(struct Payload *payload, keyType key);

void setPayloadValue(struct Payload *payload, valueType value);


#endif //UNTITLED_PAYLOAD_H
