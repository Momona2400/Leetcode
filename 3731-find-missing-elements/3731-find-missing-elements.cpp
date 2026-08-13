// class Solution {
// public:
//     vector<int> findMissingElements(vector<int>& nums) {
//         int n = nums.size();
//         ranges::sort(nums);
//         vector<int> ans;
//         for (int i = 0; i < n - 1; i++) {
//             for (int j = nums[i] + 1; j < nums[i + 1]; j++) {
//                 ans.push_back(j);
//             }
//         }
//         return ans;
//     }
// };

class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        vector<int> ans;
        sort(nums.begin(), nums.end());
        int min = nums[0], max = nums[nums.size()-1];
        // for(int i = 0; i < nums.size(); i++) {
        //     int x = nums[i];
        //     if(min > x) {
        //         min = x;
        //     }
        //     if(max < x) {
        //         max = x;
        //     }
        // }
        for(int i = 0, j = min; i < nums.size() && j <= max; ) {
            if(nums[i] == j) {
                i++;
                j++;
            }
            else {
                ans.push_back(j);
                j++;
            }
        }
        return ans;
    }
};