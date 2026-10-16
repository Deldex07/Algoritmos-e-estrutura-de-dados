int findTheWinner(int n, int k) {
    int winner = 0;

    for ( int currfriends = 2; currfriends <= n; currfriends++) {
        winner = (winner + k) % currfriends;
    }
    return winner + 1;
}