#include <stdio.h>

bool searchMatrix(int** matrix, int matrixSize, int* matrixColSize, int target){
	int row = 0;
	int col = matrixColSize[0] - 1;
	
	while (row < matrixSize && col >= 0) {
		if (matrix[row][col] == target) {return true;}
		else if (matrix[row][col] > target) {
			c --;
		}else {
			r ++;
		}
	}
	return false;

}
