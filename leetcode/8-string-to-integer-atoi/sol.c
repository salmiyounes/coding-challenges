#include <stdio.h>
#include <limits.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>

char *strstrip(char *string) {
    if (string == NULL) return NULL;

    size_t size = strlen(string);
    if (size == 0) return string;

    char *end = string + size - 1;
    while (end >= string && *end == ' ') end--;

    *(end + 1) = '\0';

    while (*string && *string == ' ') string++;

    return string;
}

int myAtoi(char* s) {
    if (s == NULL) return 0;

    s = strstrip(s);
    if (*s == '\0') return 0; 

    int sign = 1;
    size_t size = strlen(s);
    int i = 0;

    if (s[0] == '+' || s[0] == '-') {
        if (s[0] == '-') sign = -1;
        i = 1;
    }

    long long result = 0;

    for (; i < (int)size; i++) {
        if (s[i] >= '0' && s[i] <= '9') {
            result = result * 10 + (s[i] - '0');
            if (result * sign > INT_MAX) return INT_MAX;
            if (result * sign < INT_MIN) return INT_MIN;
        } else {
            break;
        }
    }

    return (int)(result * sign);
}
