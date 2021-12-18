/*  createHashTable(int numOfBuckets) -> HashTable* pointerOnHashTable    
	stringHandler(HashTable* pointerOnHashTable, char* string to handle) -> void 
	writeInFile(FILE* fileForWordCounting, HashTable* pointerOnHashTable, FILE* fileForAnalisysRecording) -> void
	
	STR_LENGTH and MAX_WORD_LENGTH are in "NAME_OF_THE_HASH_FUNCTION".h
	to change hashFunction, change the first "include" in  hashTable.h
	
	!!! Use 'Windows-1251' encoding for every header and text files, including result files !!!   */


#include "./headers/stringHandling.h"
#include <Windows.h>


void main() {
	SetConsoleCP(1251); 
	SetConsoleOutputCP(1251);
	char str[STR_LENGTH];
	FILE *fileForRead = fopen("./book/voyna-i-mir-tom-1.txt", "r");
	FILE *fileForWrite = fopen("./results/alternationSumOfCodes.txt", "w");
	FILE *fileForAnalysis = fopen("./results/analysis/alternationSumOfCodes.txt", "w");
	HashTable *table_1 = createHashTable(1);
	HashTable *table_10 = createHashTable(10);
	HashTable *table_100 = createHashTable(100);
	HashTable *table_1000 = createHashTable(1000);
	HashTable *table_10000 = createHashTable(10000);
	HashTable *table_100000 = createHashTable(100000);
	
	while (fgets(str, STR_LENGTH, fileForRead) != NULL) {
		stringHandler(table_1, str);
		stringHandler(table_10, str);
		stringHandler(table_100, str);
		stringHandler(table_1000, str);
		stringHandler(table_10000, str);
		stringHandler(table_100000, str);
	}
	writeInFile(fileForWrite, table_1, fileForAnalysis);
	writeAnalysis(fileForAnalysis, table_10);
	writeAnalysis(fileForAnalysis, table_100);
	writeAnalysis(fileForAnalysis, table_1000);
	writeAnalysis(fileForAnalysis, table_10000);
	writeAnalysis(fileForAnalysis, table_100000);
	fclose(fileForRead);
	fclose(fileForWrite);
	fclose(fileForAnalysis);
}

