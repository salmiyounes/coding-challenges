#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "split.h"

#define MAX_STRING_SIZE 10000
#define MAX_LEN_SIZE 300
#define FILENAME "input.txt"

typedef struct {
	char* name1;
	char* name2;
	bool  state;
	int   point;
} arrang;

int max(const int a, const int b) {
	return a > b ? a:b;
}

bool gainOrlose(char* string) {
	return strcmp(string, "gain") ? true : false;
}

char *
int main() {
	FILE* file = fopen(FILENAME, "r");
	if (file == NULL ) {
		return 1;
	}
	
	char* line = NULL;
	size_t len = MAX_LEN_SIZE;
	size_t read;
	
	arrang* res = (arrang *) malloc(sizeof(arrang) * MAX_STRING_SIZE);
	int resSize= 0;
	while ((read = getline(&line, &len, file)) != -1) {
		char **arr = NULL;
		int count = 0;
		count = split(line, ' ', &arr);
		res[resSize++] = (arrang) {.name1=arr[0], .name2=arr[count-1], .state=gainOrlose(arr[2]), .point=atoi(arr[3])};

	}

	for (int i = 0; i < resSize; i++) {
		arrang *curr = &res[i];
		printf("%s %s %d\n", curr->name1, curr->name2, curr->point);
	}

	fclose(file);
	free(res);
	return 0;
}
