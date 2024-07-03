#include <stdio.h>


int solve(FILE *file) {
	int nCount = 0;
	int nIndex = 0;
	int nBase = -1;
	while (!feof(file)) {
		const char c = fgetc(file);
		if (c == '(') {
			++nCount;
		} else if (c == ')') {
			--nCount;
		} else {
			continue;
		}
		nIndex ++;
		if ((-1 == nCount) && (-1 == nBase)) {
			nBase = nIndex;
		}
	}
	printf ("Part 1: %d\nPart 2: %d\n", nCount, nBase);
	return 0;
}

int main(){
	FILE *file = fopen("input.txt", "r");
	if (file == NULL) {
		printf ("Error while open file.");
		return 1;
	}
	solve(file);
	return 0;
}
