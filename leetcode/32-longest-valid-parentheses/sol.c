#define MAX 0x7530

int max(int a, int b) {
	return a > b ? a : b;
}
int longestValidParentheses(char* s) {
	if (strlen(s) == 0) return 0;
	int result = 0;
	int* stack = (int *) malloc(sizeof(int) * MAX);
	int stackSize = 0;
	stack[stackSize++] = -1;
	
	for (int i = 0; i < strlen(s) ; i++) {
		if (s[i] == '(') {
			stack[stackSize++] = i;
		} else {
			stack[stackSize--] = 0;
			if (stackSize == 0) {
				stack[stackSize++] = i;
			} else {
				result = max(result, i - stack[stackSize - 1]);
			}
		}
	}
	free(stack);
	return result;
}
