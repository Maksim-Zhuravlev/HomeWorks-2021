#include "./Headers/stringHandling.h"

void checkFilePointer(FILE *file) {
	if (file == NULL) {
		perror("Can't open the file\n");
		exit(1);
	}
}
	
void main() {
	FILE *book = fopen("./book/voyna-i-mir-tom-1.txt", "r");
	FILE *fileForResult = fopen("./result.txt", "w");
	FILE *fileForAnalysis = fopen("./analysis/polynome.txt", "w");
	char str[STR_LENGTH];
	BinaryTree *tree = initBinaryTree();
	
	checkFilePointer(book);
	checkFilePointer(fileForResult);
	checkFilePointer(fileForAnalysis);
	/*while (fgets(str, STR_LENGTH, book) != NULL) {
		stringHandler(tree, str);
	}*/
	stringHandler(tree, "\ndites. [  Ну, что, князь, Генуа и Лукка стали не больше, как поместьями фамилии ");
	printTree(tree, fileForResult);
	printTreeAnalysis(tree, fileForAnalysis);
	if (fclose(book) == EOF || fclose(fileForResult) == EOF || fclose(fileForAnalysis) == EOF) {
		perror("Can't close the file\n");
		exit(1);
	}
}