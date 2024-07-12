#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLEN 1000
#define MAXSTACK 100

typedef struct {
    char* string;
    int sum;
} Tuple;

char* repeatChar(char c, int n) {
    char* result = (char*)malloc(sizeof(char) * (n + 1));
    for (int i = 0; i < n; i++) result[i] = c;
    result[n] = '\0';
    return result;
}

char* decodeString(char* s) {
    char* result = (char*)malloc(sizeof(char) * MAXLEN);
    int sizeString = 0;
    int currNum = 0;
    Tuple stack[MAXSTACK];
    int stackSize = 0;

    for (int i = 0; i < strlen(s); i++) {
        if (s[i] >= '0' && s[i] <= '9') {
            currNum = currNum * 10 + (s[i] - '0');
        } else if (s[i] == '[') {
            stack[stackSize++] = (Tuple){ .string = result, .sum = currNum };
            currNum = 0;
            result = (char*)malloc(sizeof(char) * MAXLEN);
            sizeString = 0;
        } else if (s[i] == ']') {
            Tuple m = stack[--stackSize];
            char* prevS = m.string;
            int repeatTimes = m.sum;
            char* repeatedStr = repeatChar(*result, repeatTimes);
            strcat(prevS, repeatedStr);
            free(repeatedStr);
            result = prevS;
        } else {
            result[sizeString++] = s[i];
            result[sizeString] = '\0'; 
        }
    }

    return result;
}

int main() {
    char s[] = "3[a]2[bc]";
    char* decoded = decodeString(s);
    printf("Decoded string: %s\n", decoded);
    free(decoded); 
    return 0;
}
