#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

int min(int a, int b) {
        return a > b ? b:a;
}

int minDistance(char* word1, char* word2) {
        int n1 = strlen(word1) + 1, n2 = strlen(word2) + 1;
        int** dp = (int **) malloc(sizeof(int *) * n1);
        for (int i = 0; i < n1; i++) {
            dp[i] = (int *) malloc(sizeof(int) * n2);
            memset(dp[i], 0, sizeof(int) * n2);
        }
        for (int i = 1; i < n1; i++) { 
                dp[i][0] = i;
        }
        for (int j = 1; j < n2; j++) { 
                dp[0][j] = j;
        }

        for (int j = 1; j < n2; j++) { 
                for (int i = 1; i < n1; i++) { 
                        int substitutionCost = word1[i-1] == word2[j-1] ? 0:1;
                        dp[i][j] = min(dp[i-1][j] + 1, min(dp[i][j-1] + 1, dp[i-1][j-1] + substitutionCost));

                }
        }
        int res = dp[n1-1][n2-1];
	for (int i = 0; i < n1; i ++) {
		free(dp[i]);
	}
        free(dp);
        return res;
}

int main() {
	
    	assert(minDistance("kitten", "sitting") == 3);
   	assert(minDistance("flaw", "lawn") == 2);
    	assert(minDistance("intention", "execution") == 5);
    	assert(minDistance("", "") == 0);
   	assert(minDistance("a", "") == 1);
    	assert(minDistance("", "a") == 1);
    	assert(minDistance("a", "b") == 1);
    	assert(minDistance("abc", "yabd") == 2);
	
	return 0;
}
