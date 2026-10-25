/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* asteroidCollision(int* asteroids, int asteroidsSize, int* returnSize) {
    int j = 0;
    for( int i = 0; i < asteroids; i++ ) {
        int asteroid = asteroids[i];
        int alive = 1;

        while( j > 0 && asteroids[j - 1] > 0 && asteroid < 0 && alive ) {

            if( asteroids[j - 1] < -asteroid ) {
                j--;

            } else if( asteroids[j - 1] == -asteroid ) {
                j--;
                alive = 0;
            } else {
                alive = 0;
            }

        }
        if( alive ) {
            asteroids[j++] = asteroid;
        }
    }

    int* ans = malloc( sizeof(int) * j );

    for( int i = 0; i < j; i++ ) {
        ans[i] = asteroids[i];
    }

    *returnSize = j;
    return ans;
}