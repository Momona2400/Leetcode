class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int> check;
        vector<int> result(nums.size());
        for(int i = 0; i < nums.size(); i++) {
            if(!check.empty() && check.top() < nums[i]) {
                result[i] = -1;
                continue;
            }
            int n = nums[i];
            int j;
            for(j = i+1; j < nums.size(); j++) {
                if(nums[j] > n) {
                    result[i] = nums[j];
                    break;
                }
            }
            if(j == nums.size()) {
                for(j = 0; j < i; j++) {
                    if(nums[j] > n) {
                        result[i] = nums[j];
                        break;
                    }
                }
            }
            if(j == i) {
                result[i] = -1;
                if(!check.empty() && check.top() > nums[i]) {
                    check.push(nums[i]);
                }
            }
        }
        return result;
    }
};

// class Solution {
// public:
//     vector<int> nextGreaterElements(vector<int>& nums) {
//         stack<int> st;
//         vector<int> result (nums.size(), -1);
//         for(int i = 0; i < 2*nums.size(); i = (i+1)%nums.size()) {
            
//         }
//     }
// };