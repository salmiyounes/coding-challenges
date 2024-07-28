#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>
#include "sol.h"

int main() {
    assert(myAtoi("42") == 42);
    assert(myAtoi("   -42") == -42);
    assert(myAtoi("4193 with words") == 4193);
    assert(myAtoi("words and 987") == 0);
    assert(myAtoi("-91283472332") == INT_MIN);
    assert(myAtoi("91283472332") == INT_MAX);
    assert(myAtoi("    ") == 0);
    assert(myAtoi("") == 0);
    assert(myAtoi("  0000000000012345678") == 12345678);
    assert(myAtoi("+1") == 1);
    assert(myAtoi("+-2") == 0);
    assert(myAtoi(NULL) == 0);
    assert(myAtoi("0") == 0);
    assert(myAtoi("-0") == 0);
    assert(myAtoi("   +0 123") == 0);

    printf("All tests passed successfully.\n");

    return 0;
}
