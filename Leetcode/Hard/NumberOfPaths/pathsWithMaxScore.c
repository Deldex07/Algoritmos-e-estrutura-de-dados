/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* pathsWithMaxScore(char ** board, int boardSize, int* returnSize) {
    int* result = (int*) malloc(2 * sizeof(int));
    *returnSize = 2;
    result[0] = 0;
    result[1] = 0;
    
    int dp_s[boardSize][boardSize];
    int dp_p[boardSize][boardSize];

    dp_s[boardSize - 1][boardSize - 1] = 0;
    dp_p[boardSize - 1][boardSize - 1] = 1;

    for (int i = boardSize - 1; i >= 0; i--) {
        for (int j = boardSize - 1; j >= 0; j--) {
            
            if (i == boardSize - 1 && j == boardSize - 1) {
                continue;
            }
            
            if (board[i][j] == 'X') {
                dp_s[i][j] = 0;
                dp_p[i][j] = 0;
                continue;
            }

            int max_s = -1;
            int path_max = 0;
            //Bottom
            if (i + 1 < boardSize && dp_p[i + 1][j] > 0) {
                if (dp_s[i + 1][j] > max_s) {
                    max_s = dp_s[i + 1][j];
                    path_max = dp_p[i + 1][j];
                } else if (dp_s[i + 1][j] == max_s) {
                    path_max = (path_max + dp_p[i + 1][j]) % 1000000007;
                }
            }

            //Right
            if (j + 1 < boardSize && dp_p[i][j + 1] > 0) {
                if (dp_s[i][j + 1] > max_s) {
                    max_s = dp_s[i][j + 1];
                    path_max = dp_p[i][j + 1];
                } else if (dp_s[i][j + 1] == max_s) {
                    path_max = (path_max + dp_p[i][j + 1]) % 1000000007;
                }
            }

            // Diagonal
            if (i + 1 < boardSize && j + 1 < boardSize && dp_p[i + 1][j + 1] > 0) {
                if (dp_s[i + 1][j + 1] > max_s) {
                    max_s = dp_s[i + 1][j + 1];
                    path_max = dp_p[i + 1][j + 1];
                } else if (dp_s[i + 1][j + 1] == max_s) {
                    path_max = (path_max + dp_p[i + 1][j + 1]) % 1000000007;
                }
            }

            // Results
            if (max_s >= 0) {
                int val = (board[i][j] == 'E') ? 0 : (board[i][j] - '0');
                dp_s[i][j] = max_s + val;
                dp_p[i][j] = path_max;
            } else {
                dp_s[i][j] = 0;
                dp_p[i][j] = 0;
            }
        }
    }

    result[0] = dp_s[0][0];
    result[1] = dp_p[0][0];

    return result;
}