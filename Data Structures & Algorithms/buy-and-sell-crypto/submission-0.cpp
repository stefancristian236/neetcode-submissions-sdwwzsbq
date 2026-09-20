class Solution {
public:
    int maxProfit(std::vector<int>& prices) {
        int left = 0;  
        int right = 1; 
        int max_profit = 0;

        while (right < prices.size()) {
            if (prices[right] > prices[left]) {
                int current_profit = prices[right] - prices[left];
                max_profit = std::max(max_profit, current_profit);
            } else {
                left = right;
            }
            right++; 
        }

        return max_profit;
    }
};