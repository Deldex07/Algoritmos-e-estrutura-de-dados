//498. Diagonal Traverse
#include <stdio.h>
#include <stdlib.h>
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include <stdio.h>
#include <stdlib.h>

int* findDiagonalOrder( int** mat, int matSize, int* matColSize, int* returnSize );

int main() {
    int rows = 3;
    int cols = 3;

    int** mat = ( int** )malloc( rows * sizeof( int* ) );
    int i, j;

    for (i = 0; i < rows; i++ ) {
        mat[i] = (int*)malloc( cols * sizeof( int ) );
    }

    int count = 1;

    for ( i = 0; i < rows; i++ ) {
        for ( j = 0; j < cols; j++ ) {
            mat[i][j] = count++;
        }
    }

    int returnSize;
    int matColSize[1] = {cols};

    int* result = findDiagonalOrder( mat, rows, matColSize, &returnSize );

    printf( "Diagonal Order: " );
    for ( int i = 0; i < returnSize; i++ ) {
        printf( "%d ", result[i] );
    }
    printf( "\n" );

    free( result );
    for (i = 0; i < rows; i++ ) {
        free( mat[i] );
    }
    free( mat );

    return 0;
}

int* findDiagonalOrder(int** mat, int matSize, int* matColSize, int* returnSize) {
    if ( matSize == 0 || matColSize[0] == 0 ) {
        *returnSize = 0;
        return NULL;
    }

    int m = matSize;
    int n = matColSize[0];
    *returnSize = m * n;

    int* result = (int*)malloc( ( *returnSize ) * sizeof(int) );

    int row = 0, col = 0;
    
    for ( int i = 0; i < *returnSize; i++ ) {
        result[i] = mat[row][col];
        
        if ( ( row + col ) % 2 == 0 ) {
            if ( col == n - 1 ) {
                row++;
            } else if ( row == 0 ) {
                col++;
            } else {
                row--;
                col++;
            }
        } else {

            if ( row == m - 1 ) {
                col++;
            } else if ( col == 0 ) {
                row++;
            } else {
                row++;
                col--;
            }
        }
    }

    return result;
}