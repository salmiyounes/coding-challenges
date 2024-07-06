#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int max(int a, int b) {
        return a > b ? a:b;
}

int longestSubstringUtil(char* s, int start, int end, int k) {
        if (end < k) return 0;

        int* countMap = (int *) malloc(sizeof(int) * 26);
        memset(countMap, 0, sizeof(int) * 26);

        for (int i = start; i < end; i++) {countMap[s[i] - 'a'] ++;}

        for (int mid = start; mid < end; mid++) {
                if (countMap[s[mid] - 'a'] >= k) continue;
                int midNext = mid + 1;
                while (midNext < end && (countMap[s[midNext] - 'a'] < k)) {
                    midNext ++;
                }
                free(countMap);
                return max(longestSubstringUtil(s, start, mid, k), longestSubstringUtil(s, midNext, end, k));
        }
        free(countMap);
        return (end - start);
}

int longestSubstring(char* s, int k) {
        return longestSubstringUtil(s, 0, strlen(s), k);
}

int main() {
	return 0;
}
