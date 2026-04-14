/*
Dynamic Programming
Time: O(n)
*/

int maxProfit(int* prices, int pricesSize, int fee) {
    int hold = -prices[0];
    int cash = 0;

    for (int i = 1; i < pricesSize; i++) {
        cash = (cash > hold + prices[i] - fee) ? cash : hold + prices[i] - fee;
        hold = (hold > cash - prices[i]) ? hold : cash - prices[i];
    }

    return cash;
}