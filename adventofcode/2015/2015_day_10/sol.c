#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 0x5f5e100

void reverse(char* string) {
    if (string == NULL) return;

    if (*string == '\0') return;

    char *start = string;
    char *end = start + strlen(string) - 1;
    char temp;

    while (end > start) {
        temp = *start;
        *start = *end;
        *end = temp;

        ++start;
        --end;
    }
}

char* int2str(int number) {
    char* result = (char*)malloc(sizeof(char) * 20); 
    char nums[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
    int resSize = 0;

    if (number == 0) {
        result[resSize++] = '0';
    } else {
        while (number > 0) {
            result[resSize++] = nums[number % 10];
            number = number / 10;
        }
    }

    result[resSize] = '\0';
    reverse(result);
    return result;
}

char* lookAndSay(char* num) {
    char* result = (char*)malloc(sizeof(char) * MAX); 
    int index = 0, count = 0, resSize = 0;
    char curr = num[0];

    while (index < strlen(num)) {
        if (num[index] == curr) {
            count++;
            index++;
        } else {
            char* countStr = int2str(count);
            int countStrLen = strlen(countStr);
            for (int i = 0; i < countStrLen; i++) {
                result[resSize++] = countStr[i];
            }
            result[resSize++] = curr;
            free(countStr);

            curr = num[index];
            count = 1;
            index++;
        }
    }

    char* countStr = int2str(count);
    int countStrLen = strlen(countStr);
    for (int i = 0; i < countStrLen; i++) {
        result[resSize++] = countStr[i];
    }
    result[resSize++] = curr;
    free(countStr);

    result[resSize] = '\0';
    return result;
}

int main() {
    	char* number = (char *) malloc(sizeof(char) * MAX);
	char* c = "3113322113";
	strncpy(number, c, strlen(c));
	number[strlen(c)] = '\0';
	for (int i = 0; i < 40; i++) {
		char* newstring = lookAndSay(number);
    		strncpy(number, newstring, strlen(newstring));
		free(newstring);
	}
    	printf("Part 1: %ld\n", strlen(number));
    	return 0;
}
