#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#define MAX 0xf4240

void bck(char** memo, char* string, int n, int right, int left, int stringSize, int *memoSize) {
	if (left == n && right == n) {
		string[stringSize] = '\0';
        memo[*memoSize] = (char *) malloc((stringSize + 1) * sizeof(char));
        strcpy(memo[*memoSize], string);
        (*memoSize)++;
		return ;
	}
	if (left < n) {
		string[stringSize] = '(';
		bck(memo, string, n, right, left+1, stringSize + 1, memoSize);
	}
	if (right < left) {
		string[stringSize] = ')';
		bck(memo, string, n, right + 1, left, stringSize + 1, memoSize);
	}
}

char** generateParenthesis(int n, int* returnSize) {
	char** memo = (char**) malloc(sizeof(char *) * MAX);
	int memoSize = 0;
	char* string = (char *) malloc(sizeof(char) * MAX);
	bck(memo, (char *) malloc(sizeof(char) * MAX), n, 0, 0, 0, &memoSize);
    	free(string);
    	*returnSize = memoSize;
    	return memo;
}

int main() {
 	 int returnSize;
    	char** result;

    result = generateParenthesis(1, &returnSize);
    assert(returnSize == 1);
    assert(strcmp(result[0], "()") == 0);
    for (int i = 0; i < returnSize; i++) free(result[i]);
    free(result);

    result = generateParenthesis(2, &returnSize);
    assert(returnSize == 2);
    assert((strcmp(result[0], "(())") == 0 || strcmp(result[0], "()()") == 0));
    assert((strcmp(result[1], "(())") == 0 || strcmp(result[1], "()()") == 0));
    for (int i = 0; i < returnSize; i++) free(result[i]);
    free(result);

    result = generateParenthesis(3, &returnSize);
    assert(returnSize == 5);
    const char* expectedResults3[] = {"((()))", "(()())", "(())()", "()(())", "()()()"};
    int foundResults3[5] = {0};
    for (int i = 0; i < returnSize; i++) {
        for (int j = 0; j < 5; j++) {
            if (strcmp(result[i], expectedResults3[j]) == 0) {
                foundResults3[j] = 1;
                break;
            }
        }
        free(result[i]);
    }
    free(result);
    for (int i = 0; i < 5; i++) {
        assert(foundResults3[i] == 1);
    }

    printf("All tests passed!\n");
    return 0;
}
