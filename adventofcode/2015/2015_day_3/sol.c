#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX 0xf4240

typedef struct {
	int x;
	int y;
} Tuple;

bool isHere(Tuple* set, int Size, Tuple state) {
	for (int i = 0; i < Size; i++) {
		if (set[i].x == state.x && set[i].y == state.y) return true;
	}
	
	return false;
}

int makeVisit(char* data, Tuple state, Tuple* visited, int Size) {
	visited[Size++] = (Tuple) {.x=state.x, .y=state.y};
	for (int i = 0; i < strlen(data); i++) {
		if (data[i] == '>') state.x++;
		if (data[i] == '<') state.x--;
		if (data[i] == '^') state.y++;
		if (data[i] == 'v') state.y--;
		if (!(isHere(visited, Size, state))) visited[Size++] = (Tuple) {.x=state.x, .y=state.y};
	}
	
	return Size;
}

int main() {
	FILE* file = fopen("input.txt", "r");
	if (file == NULL) {
		printf ("Error while open file.\n");
		return 1;
	}
	char* list = (char *) malloc(sizeof(char) * MAX);
	int listSize = 0;
	char read;
	while ((read = fgetc(file)) != EOF) {
		list[listSize++] = read;
	}
	list[listSize] = '\0';
	fclose(file);
	Tuple state = {.x=0, .y=0};
	Tuple* visited = (Tuple *) malloc(sizeof(Tuple) * MAX);
	int result = makeVisit(list, state, visited, 0);
	printf("Part 1: %d\n", result);
	free(list);
	free(visited);
	return 0;
}

