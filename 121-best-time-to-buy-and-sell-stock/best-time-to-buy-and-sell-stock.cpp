class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mini = INT_MAX;
        int profit = 0;

        for (int price : prices) {
            mini = min(mini, price);
            profit = max(profit, price - mini);
        }

        return profit;
    }
};