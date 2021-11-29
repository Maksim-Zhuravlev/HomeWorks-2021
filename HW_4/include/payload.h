#ifndef UNTITLED_PAYLOAD_H
#define UNTITLED_PAYLOAD_H


#define MAX_WORD_LENGTH 128

#include <wchar.h>

typedef int valueType;
typedef wchar_t keyType[MAX_WORD_LENGTH + 1];
typedef wchar_t keyType_;


struct Payload {
    keyType key;
    valueType value;
};


void printPayload(struct Payload data);

int compareKeys(keyType key1, keyType key2);

void setPayloadKey(struct Payload *payload, keyType key);

void setPayloadValue(struct Payload *payload, valueType value);

int compare_payloads(const void *a, const void *b);
#endif //UNTITLED_PAYLOAD_H
