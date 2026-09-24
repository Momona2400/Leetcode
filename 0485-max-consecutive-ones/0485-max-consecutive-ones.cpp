class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int start = 0, ans = 0;
        for(int end = 0; end < nums.size(); end++) {
            if(nums[end] == 0) {
                start = end+1;
            }
            ans = max(ans, end-start+1);
        }
        return ans;
    }
};