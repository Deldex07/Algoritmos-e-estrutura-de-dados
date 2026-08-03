#define MAX(a, b) ((a) > (b) ? (a) : (b))
char* stoneGameIII(int* stoneValue, int stoneValueSize) {
    int next1 = 0, next2 = 0, next3 = 0;

    for( int i = stoneValueSize - 1; i >= 0; i-- ) {
        int curr = 0;
        int diff = -2e9;

        curr = stoneValue[i];
        diff = MAX( diff, curr - next1 );

        if(i + 1 < stoneValueSize ) {
            curr += stoneValue[i+1];
            diff = MAX( diff, curr - next2 );
        }

        if(i + 2 < stoneValueSize) {
            curr += stoneValue[i+2];
            diff = MAX( diff, curr - next3 );
        }
        next3 = next2;
        next2 = next1;
        next1 = diff;
    }

    if (next1 > 0) return "Alice";
    if (next1 < 0) return "Bob";
    return "Tie";
}