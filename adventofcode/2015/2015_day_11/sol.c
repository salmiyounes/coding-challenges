#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

bool Rule1(const char *string) {
    if (strlen(string) < 3) return false;
    char strings[][4] = {"abc", "bcd", "cde", "def", "efg", "fgh", "pqr", "qrs", "rst", "stu", "tuv", "uvw", "vwx", "wxy", "xyz"};
    char curr[4] = {0};
    for (int i = 0; i <= strlen(string) - 3; i++) {
        strncpy(curr, string + i, 3);
        curr[3] = '\0';
        for (int j = 0; j < 15; j++) {
            if (strcmp(curr, strings[j]) == 0) return true;
        }
    }
    return false;
}

bool Rule2(const char *string) {
    for (int i = 0; i < strlen(string); i++) {
        if (string[i] == 'i' || string[i] == 'o' || string[i] == 'l') return false;
    }
    return true;
}

bool Rule3(const char *string) {
    int len = strlen(string);
    for (int i = 0; i < len - 1; i++) {
        if (string[i] == string[i + 1]) {
            for (int j = i + 2; j < len - 1; j++) {
                if (string[j] == string[j + 1]) return true;
            }
        }
    }
    return false;
}

char *countLetters(char *curr, const int Size, const char *letters) {
    char *result = (char *)malloc(sizeof(char) * (Size + 1));
    while (true) {
        if (Rule2(curr) && Rule1(curr) && Rule3(curr)) {
            strcpy(result, curr);
            return result;
        }
        if (curr[Size - 1] == 'z') {
            curr[Size - 1] = 'a';
            bool flag = true;
            int index = Size - 2;

            while (index >= 0 && flag) {
                if (curr[index] != 'z') {
                    curr[index] = letters[curr[index] - 'a' + 1];
                    flag = false;
                } else {
                    curr[index] = 'a';
                }
                index--;
            }
        } else {
            curr[Size - 1] = letters[curr[Size - 1] - 'a' + 1];
        }
    }
    free(result);
    return NULL;
}

int main() {
    char password[] = "hxbxwxba";
    const int pasSize = strlen(password);
    char letters[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

    char *result = countLetters(password, pasSize, letters);
    printf("Part 1: %s\n", result);
    free(result); 
    return 0;
}
