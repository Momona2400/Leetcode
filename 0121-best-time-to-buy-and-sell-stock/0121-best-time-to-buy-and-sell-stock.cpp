class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min = prices[0], gain1 = 0, gain2;
        for(int i = 0; i < prices.size(); i++) {
            if(min > prices[i]) {
                min = prices[i];
            }
            gain2 = prices[i] - min;
            if(gain1 < gain2) {
                gain1 = gain2;
            }
        }
        return gain1;
    }
};