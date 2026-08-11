class Solution {
public:
    int minimumCost(vector<int>& nums, int k) {
        long long cost = 1;
        long long s = k;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] <= s) {
                s-=nums[i];
            }
            else {
                cost += (nums[i]-s+k-1)/k;
                s += ((nums[i]-s+k-1)/k) * k;
                s-=nums[i];
            }
        }
        cost--;
        cost = cost%1000000007;
        long long sum;
        if(cost%2==0) {
            sum = (cost/2) * (cost+1);
        }
        else {
            sum = cost * ((cost+1)/2);
        }
        return sum%1000000007;
    }
};