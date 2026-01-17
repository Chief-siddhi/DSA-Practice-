#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxProfit(vector<int>& prices) {
    int n = prices.size();
    if (n == 0) return 0;

    vector<int> maxPrice(n);
    maxPrice[n - 1] = prices[n - 1];

    // Build max price array from right
    for (int i = n - 2; i >= 0; i--) {
        maxPrice[i] = max(maxPrice[i + 1], prices[i]);
    }

    int profit = 0;
    for (int i = 0; i < n; i++) {
        profit = max(profit, maxPrice[i] - prices[i]);
    }

    return profit;
}
