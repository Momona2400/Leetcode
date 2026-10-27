class Solution {
public:
    int subarraySum(vector<int>& nums, int K) {
        int N = nums.size();
        vector<int> prefixsum(N);
        prefixsum[0] = nums[0];
        for(int i = 1; i <  N; i++) {
            prefixsum[i] = prefixsum[i-1] + nums[i];
        }
        unordered_map<int, int> um;
        um[0]++;
        int count = 0;
        for(int i = 0; i < N; i++) {
            if(um.find(prefixsum[i] - K) != um.end()) {
                count+=um[prefixsum[i]-K];
            }
            um[prefixsum[i]]++;
        }
        return count;
    }
};