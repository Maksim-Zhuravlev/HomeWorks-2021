#include <stdio.h>
#include <string.h>

#include "../include/payload.h"


void printPayload(struct Payload data) {
    wprintf(L"key = %S\t\tvalue = %d\n", data.key, data.value);
}

int compareKeys(keyType key1, keyType key2) {
    return wcscmp(key1, key2);
}

int compare_payloads(const void *a, const void *b) {
    struct Payload *p1 = *(struct Payload **) a;
    struct Payload *p2 = *(struct Payload **) b;

    return compareKeys(p1->key, p2->key);
}

void setPayloadKey(struct Payload *payload, keyType key) {
    wcscpy(payload->key, key);
}

void setPayloadValue(struct Payload *payload, valueType value) {
    payload->value = value;
}
