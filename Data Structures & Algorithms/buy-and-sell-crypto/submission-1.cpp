class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int i = 0;
        int j = 1;
        int buy = 0;
        int sell = 0;
        int profit = 0;

        while(j < prices.size()){
            if(prices[i] > prices[j]){
                i = j;
            }
            else {
                profit = max(profit, prices[j] - prices[i]);
            }
            j++;
        }
        return profit;
    }
};