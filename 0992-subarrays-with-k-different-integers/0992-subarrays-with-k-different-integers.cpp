class Solution {
public:
    int atmost(int N, int K, vector<int>& nums) {
        unordered_map<int, int> um;
        int start = 0, count = 0;
        for(int end = 0; end < N; end++) {
            um[nums[end]]++;
            while(um.size() > K) {
                um[nums[start]]--;
                if(um[nums[start]] == 0) {
                    um.erase(nums[start]);
                }
                start++;
            }
            count+=end-start+1;
        }
        return count;
    }

    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atmost(nums.size(), k, nums) - atmost(nums.size(), k-1, nums);
    }
};