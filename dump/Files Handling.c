#include <stdio.h>
#include <stdlib.h>

#define SIZE 100

int main() {
	// Open a file named file.txt and write to it.
	FILE* fp;
	fp = fopen("file.txt","a");
	if (fp == NULL) {
		printf("Error in opening the file.\n");
		exit(1);
	}
	fprintf(fp,"This is an example of writing to a file.\n");
	fclose(fp);

	//open a file name to read its contents.
	fp = fopen("file.txt", "r");
	if (fp == NULL) {
		printf("Error in opening the file.\n");
		exit(1);
	}
	char buffer[SIZE] = { '\0' };
	if (fgets(buffer, SIZE, fp) == 0) {
		printf("Error reading contents of the file.\n");
		exit(1);
	}
	printf("Content of the file: %s", buffer);
	fclose(fp);
	return 0;
}