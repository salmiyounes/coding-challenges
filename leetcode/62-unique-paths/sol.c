#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

typedef struct {
        int x;
        int y;
} Point;

int bck(const Point curr, int **memo, int m, int n);

int uniquePaths(int m, int n) {

        if (n == 1 && m == 1) {
                return 1;
        }
        int **memo = (int **) malloc(sizeof(int*) * m);
        for (int i = 0; i < m; i++) {
                memo[i] = (int *) malloc(sizeof(int) * n);
                for (int j = 0; j < n; j++) {
                        memo[i][j] = -1;
                }
        }
        const Point curr = {0,0};
        int res = bck(curr, memo, m, n);
        for (int i = 0; i < m; i++) {
                free(memo[i]);
        }

        free(memo);
        return res;
}

int bck(const Point curr, int **memo, int m, int n) {
        int x = curr.x;
        int y = curr.y;
        if (x == m - 1 && y == n - 1) {return 1;}
        else if (memo[x][y] != -1) {return memo[x][y];}
        int right = 0;
        int left  = 0;
        if (x + 1 <= m - 1) {
                const Point curr = {x+1, y};
                left += bck(curr, memo, m, n);
        } 
        if (y + 1 <= n - 1) {
                const Point curr = {x, y+1};
                right += bck(curr, memo, m, n);
        }
        memo[x][y] = left + right;
        return memo[x][y];

}

int main() {
	assert(uniquePaths(3, 2) == 3);
	assert(uniquePaths(3,7)  == 28);
	assert(uniquePaths(19, 10) == 4686825);
	return 0;

}
