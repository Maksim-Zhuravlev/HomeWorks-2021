#include "./Headers/stringHandling.h"

void checkFilePointer(FILE *file) {
	if (file == NULL) {
		perror("Can't open the file\n");
		exit(1);
	}
}


void main() {
	FILE *book = fopen("./Book/voyna-i-mir.txt", "r");
	FILE *results = fopen("./Output/Results.txt", "w");
	FILE *analysis = fopen("./Output/Analysis.txt", "w");
	char str[STR_LENGTH];
	BinaryTree *tree = initBinaryTree();
	
	checkFilePointer(book);
	checkFilePointer(results);
	checkFilePointer(analysis);
	while (fgets(str, STR_LENGTH, book) != NULL) {
		stringHandler(tree, str);
	}
	printTree(tree, results);
	printTreeAnalysis(tree, analysis);
	deleteTree(&tree);
	treeDeletedChecker(tree);
	if (fclose(book) == EOF || fclose(results) == EOF || fclose(analysis) == EOF) {
		perror("Can't close the file\n");
		exit(1);
	}
}
