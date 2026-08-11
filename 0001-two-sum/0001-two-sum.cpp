class Solution {
public:

    int t;

    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        for(int i = 0; i < nums.size(); i++) {
            int f=0;
            for(int j = 0; j < i; j++) {
                if(nums[i]+nums[j] == target) {
                    result.push_back(i);
                    result.push_back(j);
                    f=1;
                    break;
                }
            }
            if(f==1)
            break;
            for(int k = i+1; k < nums.size(); k++) {
                if(nums[i]+nums[k] == target) {
                    result.push_back(i);
                    result.push_back(k);
                    f=1;
                    break;
                }
            }
            if(f==1)
            break;
        }
        return result;
    }
};