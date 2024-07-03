# include <stdio.h>

# define MAX 10000000

int min(int a, int b) {
	return (a <= b) ? a:b;
}

int bck(int** grid, int gridSize, int* gridColSize, int** memo, int x, int y) {
	if (x >= gridSize || y >= gridColSize) {
		return MAX;
	}
	if (x == gridSize -1 && y == gridColSize -1) {
		return grid[x][y];
	}
	if (memo[x][y] != -1) {
		return memo[x][y];
	}
	
	int right = bck(grid, gridSize, gridColSize, grid, x+1, y);
	int left  = bck(grid, gridSize, gridColSize, grid, x, y+1);
	memo[x][y] = grid[x][y] + min(right, down);
	return memo[x][y];
}
int minPathSum(int** grid, int gridSize, int* gridColSize) {
    	int memo[gridSize][gridColSize];
    	for (int i = 0; i < gridZise; i++) {
		for (int j = 0; j < gridColSize; j++) {
			memo[i][j] = -1;
		}
    	}
	bck(grid, gridSize, gridColSize, memo, 0, 0);
	return memo[0][0];

}

