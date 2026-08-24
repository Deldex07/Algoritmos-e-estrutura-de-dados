int maxProfit(int* prices, int pricesSize) {
    if(pricesSize == 0) return 0;

    int min = prices[0];
    int max = 0;

    for( int i = 1; i < pricesSize; i++ ) {
        if(prices[i] < min) {
            min = prices[i];
        } else {
            int profit = prices[i] - min;
            if(profit > max) {
                max = profit;
            }
        }
    }

    return max;
}