#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

bool contains(char* list, int size, char opp) {
    for (int i = 0; i < size; i++) {
        if (list[i] == opp) return true;
    }
    return false;
}

int evalRPN(char** tokens, int tokensSize) {
    int* stack = (int *)malloc(sizeof(int) * tokensSize);
    memset(stack, 0, sizeof(int) * tokensSize);
    int stackSize = 0;
    char operators[4] = {'+', '-', '*', '/'};

    for (int i = 0; i < tokensSize; i++) {
        if (!contains(operators, 4, tokens[i][0]) || (tokens[i][1] != '\0')) {
            stack[stackSize++] = atoi(tokens[i]);
        } else {
            int num2 = stack[--stackSize];
            int num1 = stack[--stackSize];
            switch (tokens[i][0]) {
                case '+':
                    stack[stackSize++] = num1 + num2;
                    break;
                case '-':
                    stack[stackSize++] = num1 - num2;
                    break;
                case '*':
                    stack[stackSize++] = num1 * num2;
                    break;
                case '/':
                    stack[stackSize++] = num1 / num2;
                    break;
            }
        }
    }
    int result = stack[--stackSize];
    free(stack);
    return result;
}
