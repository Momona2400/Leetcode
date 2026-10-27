class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int K) {
        int N = nums.size();
        if(K <= 1) {
            return 0;
        }
        if(N == 1) {
            if(nums[0] < K) {
                return 1;
            }
            return 0;
        }
        int start = 0, temp = 0;
        long long pro = 1;
        long count = 0;
        for(int end = 0; end < N; end++) {
            pro *= nums[end];
            if(pro < K) {
                count += end-start+1;
            }
            int pro2 = pro;
            if(pro2 >= K) {
                while(pro2 >= K) {
                    pro2 /= nums[temp];
                    temp++;
                }
                count += end-temp+1;
                while(pro >= K) {
                    pro /= nums[start];
                    start++;
                }
            }
        }
        return count;
    }
};