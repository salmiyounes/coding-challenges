#define MAX 128

typedef struct {
    char key;
    int value;
} item;

int max(int a, int b) {
    return a > b ? a : b;
}

bool containkey(item* map, char key) {
    return map[(int)key].key == key;
}

int getValue(item* map, char key) {
    if (containkey(map, key)) {
        return map[(int)key].value;
    }
    return -1;  
}

void put(item* map, char key, int value) {
    map[(int)key].key = key;
    map[(int)key].value = value;
}

int lengthOfLongestSubstring(char* s) {
    if (strlen(s) <= 1) return strlen(s);
    item* map = (item *) calloc(MAX, sizeof(item));
    int maxLen = 0, start = 0, end = 0;

    for (end = 0; end < strlen(s); end++) {
        if (containkey(map, s[end]) && getValue(map, s[end]) >= start) {
            start = getValue(map, s[end]) + 1;
        }
        put(map, s[end], end);
        int currLen = end - start + 1;
        maxLen = max(maxLen, currLen);
    }

    free(map);
    return maxLen;
}


