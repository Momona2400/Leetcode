class Solution {
public:
    int partitionDisjoint(vector<int>& nums) {
        int N = nums.size();
        vector<int> maxlef(N), minrig(N);
        maxlef[0] = nums[0];
        minrig[N-1] = nums[N-1];
        for(int i = 1; i < N; i++) {
            maxlef[i] = max(maxlef[i-1], nums[i]);
        }
        for(int i = N-2; i >= 0; i--) {
            minrig[i] = min(minrig[i+1], nums[i]);
        }
        for(int i = 0; i < N-1; i++) {
            if(maxlef[i] <= minrig[i+1]) {
                return i+1;
            }
        }
        return 0;
    }
};