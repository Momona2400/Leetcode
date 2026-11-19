class Solution {
public:
    int minimumSum(vector<int>& nums) {
        int N = nums.size();
        vector<int> minlef(N), minrig(N);
        int ans = INT_MAX;
        minlef[0] = nums[0];
        minrig[N-1] = nums[N-1];
        for(int i = 1; i < N; i++) {
            minlef[i] = min(minlef[i-1], nums[i]);
        }
        for(int i = N-2; i >= 0; i--) {
            minrig[i] = min(minrig[i+1], nums[i]);
        }
        for(int i = 1; i < N-1; i++) {
            if(nums[i] > minlef[i-1] && nums[i] > minrig[i+1]) {
                ans = min(ans, nums[i]+minlef[i-1]+minrig[i+1]);
            }
        }
        if(ans == INT_MAX) {
            return -1;
        }
        return ans;
    }
};