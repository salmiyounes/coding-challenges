#include <stdio.h>

char* expand(char* s, int l, int r) {
	while (l >= 0 && r < strlen(s) && s[l] == s[r]) {
		l --;
		r ++;
	}
	char *p = (char *) malloc(sizeof(char) * (r - l));
	memcpy(p, &s[l+1], sizeof(char) * (r - l - 1));
	p[r - l - 1] = '\0';
	return p;
}

char* longestPalindrome(char* s) {
	if (!s || strlen(s) == 0) return s;
	int start = 0, len = 0;
	for (int i = 0; i < strlen(s); i++) {
		char *odd  = expand(s, i, i);
		char *even = expand(s, i, i+1);
		int max_len = strlen(odd) > strlen(even) ? strlen(odd) : strlen(even);
		
		if (max_len > len) {
			start = i - (max_len -1) /2;
			len = max_len;
		}

		free(odd);
		free(even);
	}
	
	char *ans = (char *) malloc(sizeof(char) * (len +  1));
	strncpy(ans,&s[start], len);
	ans[len] = '\0';
	return ans;
}
