typedef struct { 
        char  key;
        int value;
} item;

void reverse(char* string) { 
        char* left = string;
        char* right = string + strlen(string) - 1;

        while (left < right) { 
                char temp = *left;
                *left = *right;
                *right = temp;
                left ++;
                right --;
        }
}
int getValue(item* map, char key, int mapSize) { 
        for (int i = 0; i < mapSize; i++) { 
                if (map[i].key == key) return map[i].value;
        }
        return 0;
}
int romanToInt(char* s) {
        int mapSize = 7;
        item* map = (item *) malloc(sizeof(item) * mapSize);
        map[0].key = 'I'; map[0].value = 1;
        map[1].key = 'V'; map[1].value = 5;
        map[2].key = 'X'; map[2].value = 10;
        map[3].key = 'L'; map[3].value = 50;
        map[4].key = 'C'; map[4].value = 100;
        map[5].key = 'D'; map[5].value = 500;
        map[6].key = 'M'; map[6].value = 1000;
        reverse(s);
        int prev = 0, total = 0;
        for (int i = 0; i < strlen(s); i ++) { 
                int curr = getValue(map, s[i], mapSize);
                if (curr < prev) { 
                        total -= curr;
                }else { 
                        total += curr;
                }
                prev = curr;
        }
        free(map);
        return total;
} 
