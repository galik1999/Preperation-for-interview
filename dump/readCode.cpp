#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 4096
int main() {
	//Reading code as a file.
	FILE* fp;
	const char* fileName = "BFS_tree.c";
	//open the file.
	fp = fopen(fileName, "r");
	if (fp == NULL) {
		printf("Error opening the file: %s", fileName);
		exit(1);
	}
	char buffer[MAX_SIZE] = { 0 };
	//read the conents of the file.
	// each call to fgets advances the file pointer forward.
	while (fgets(buffer, MAX_SIZE, fp) != NULL) {
		puts(buffer);
	}
	return 0;
}