class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int N = nums.size();
        vector<int> prefixsum(N);
        prefixsum[0] = nums[0];
        for(int i = 1; i < N; i++) {
            prefixsum[i] = prefixsum[i-1] + nums[i];
        }
        for(int i = 0; i < N; i++) {
            if(i == 0) {
                if(prefixsum[N-1]-prefixsum[i] == 0) {
                    return 0;
                }
            }
            else if(prefixsum[i-1] == prefixsum[N-1]-prefixsum[i]) {
                return i;
            }
        }
        return -1;
    }
};