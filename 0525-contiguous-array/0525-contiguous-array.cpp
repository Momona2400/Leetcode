class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int N = nums.size();
        vector<int> prefixsum(N);
        int sum = 0;
        for(int i = 0; i < N; i++) {
            if(nums[i] == 0) {
                sum--;
            }
            else {
                sum++;
            }
            prefixsum[i] = sum;
        }
        unordered_map<int, int> um;
        um[0] = -1;
        int maxlen = 0;
        for(int i = 0; i < N; i++) {
            if(um.find(prefixsum[i]) != um.end()) {
                maxlen = max(maxlen, i-um[prefixsum[i]]);
            }
            else {
                um[prefixsum[i]] = i;
            }
        }
        return maxlen;
    }
};