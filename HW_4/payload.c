#include <stdio.h>
#include <string.h>

#include "payload.h"


void printPayload(struct Payload data) {
    printf("key = %s\t\tvalue = %d\n", data.key, data.value);
}

_Bool compareKeys(keyType key1, keyType key2) {
    return !strcasecmp(key1, key2);
}

void setPayloadKey(struct Payload *payload, keyType key) {
    strcpy(payload->key, key);
}

void setPayloadValue(struct Payload *payload, valueType value) {
    payload->value = value;
}
