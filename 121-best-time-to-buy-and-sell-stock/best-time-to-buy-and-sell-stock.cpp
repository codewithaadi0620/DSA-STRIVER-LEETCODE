class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = prices[0];
        int maxProfit = 0;

        for (int i = 1; i < prices.size(); i++) {
            // Update the lowest price encountered so far
            minPrice = min(minPrice, prices[i]);

            // Calculate profit if sold today, and update max profit
            maxProfit = max(maxProfit, prices[i] - minPrice);
        }

        return maxProfit;
    }
};