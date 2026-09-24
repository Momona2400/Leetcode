class Solution {
public:
    int longestSubarray(vector<int>& nums) {
    int start = 0, noz = 0, ans = 0;
    for(int end = 0; end < nums.size(); end++) {
      if(nums[end] == 0) {
        noz++;
      }
      if(noz > 1) {
        while(nums[start] == 1) {
          start++;
        }
        start++;
        noz--;
      }
      ans = max(ans, end-start+1);
    }
    return ans-1;
    }
};