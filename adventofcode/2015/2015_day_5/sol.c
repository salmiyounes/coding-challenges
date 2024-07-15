#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define SIZE 0x12c

int countVowl(char* line) {
	int count = 0;
	for (int i = 0; i < strlen(line); i++) {
		char c = line[i];
		if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') count ++;
	}
	
	return count;
}

bool forbiden(char* line) {
	char** x = (char **) malloc(sizeof(char*) * 4);
	for (int i = 0; i < 4; i++) {
		x[i] = (char *) malloc(sizeof(char) * 3);
	}

	strcpy(x[0],"ab") , strcpy(x[1], "cd"), strcpy(x[2], "pq"), strcpy(x[3], "xy");
	for (int i = 1; i < strlen(line) ; i++) {
		char* string = (char *) malloc(sizeof(char) * 3);
		string[0] = line[i-1], string[1] = line[i], string[2] = '\0';
		for (int b = 0; b < 4; b++) {
			if (strcmp(string, x[b]) == 0) {
				free(string);
				free(x);
				return true;
			}
		}
		free(string);
	}
	
	free(x);
	return false;
}

bool twoChar(char* line) {
	for (int i = 1; i < strlen(line); i++) {
		if (line[i-1] == line[i]) return true;
	}
	
	return false;
}

void solve(char* line, int* count) {
	if (countVowl(line) >= 3 && twoChar(line) && !(forbiden(line))) ++*(count);
}

int main() {
	FILE* file = fopen("input.txt", "r");
	if (file == NULL) {
		printf ("Error while open file.\n");
		return 1;
	}
	char* line = NULL; size_t len = SIZE; ssize_t read;
	int count = 0;
	while ((read = getline(&line, &len, file)) != -1) {
		solve(line, &count);
	}
	fclose(file);
	if (line) free(line);
	printf ("Part 1: %d\n", count);
	return 0;
}
