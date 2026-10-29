bool searchMatrix(int** matrix, int matrixSize, int* matrixColSize, int target) {
    int cols = matrixColSize[0];
    int left = 0;
    int right = (matrixSize * cols) - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        int row = mid / cols;
        int col = mid % cols;
        int val = matrix[row][col];

        if (val == target) {
            return true;
        } else if (val < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return false;
}