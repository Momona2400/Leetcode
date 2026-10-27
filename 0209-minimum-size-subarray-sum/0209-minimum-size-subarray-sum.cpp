class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int N = nums.size(), K = target;
        int start = 0, minlen = INT_MAX, sum = 0;
        for(int end = 0; end < N; end++) {
            sum+=nums[end];
            while(sum>=target) {
                minlen = min(minlen, end-start+1);
                sum-=nums[start];
            start++;
            }
        }
        if(minlen == INT_MAX) {
            return 0;
        }
        return minlen;
    }
};