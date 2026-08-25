// class Solution {
// public:
//     vector<vector<int>> threeSum(vector<int>& nums) {
//         vector<vector<int>> ans;
//         for(int i = 0; i < nums.size(); i++) {
//             for(int j = i+1; j < nums.size(); j++) {
//                 for(int k = j+1; k < nums.size(); k++) {
//                     if(nums[i] + nums[j] + nums[k] == 0) {
//                         vector<int> temp;
//                         temp.push_back(nums[i]);
//                         temp.push_back(nums[j]);
//                         temp.push_back(nums[k]);
//                         sort(temp.begin(), temp.end());
//                         ans.push_back(temp);
//                     }
//                 }
//             }
//         }
//         sort(ans.begin(), ans.end());
//         ans.erase(unique(ans.begin(), ans.end()), ans.end());
//         return ans;
//     }
// };



// class Solution {
// public:
//     vector<vector<int>> threeSum(vector<int>& nums) {
//         // nums.erase(unique(nums.begin(), nums.end()), nums.end());
//         vector<vector<int>> ans;
//         // if(nums.size() == 1) {
//         //     if(nums[0] == 0) {
//         //         ans.push_back({0, 0, 0});
//         //     }
//         //     return ans;
//         // }
//         int i = 0, j = nums.size()-1, turn = 0;
//         while(i < j) {
//             if(turn == 3) {
//                 turn = 1;
//             }
//             else {
//                 turn++;
//             }
//             int x = nums[i]+nums[j];
//             int diff = 0 - x;
//             vector<int> ans1;
//             for(int k = i+1; k < j; k++) {
//                 if(nums[k] == diff) {
//                     ans1.push_back(nums[i]);
//                     ans1.push_back(nums[j]);
//                     ans1.push_back(nums[k]);
//                     break;
//                     sort(ans1.begin(), ans1.end());
//                     break;
//                 }
//             }
//             if(!ans1.empty()) {
//                 ans.push_back(ans1);
//             }
//             if(turn == 1) {
//                 i++;
//             }
//             else if(turn == 2) {
//                 i--;
//                 j--;
//             }
//             else if(turn == 3) {
//                 i++;
//             }
//         }
//         ans.erase(unique(ans.begin(), ans.end()), ans.end());
//         return ans;
//     }
// };




// class Solution {
// public:
//     vector<vector<int>> threeSum(vector<int>& nums) {
//         vector<vector<int>> ans;
//         int i = 0, j = nums.size()-1, turn = 0;
//         for(int i = 0; i < nums.size(); i++) {
//             j = nums.size()-1;
//             while(i < j) {
//                 int x = nums[i]+nums[j];
//                 int diff = 0 - x;
//                 vector<int> ans1;
//                 for(int k = i+1; k < j; k++) {
//                     if(nums[k] == diff) {
//                         ans1.push_back(nums[i]);
//                         ans1.push_back(nums[j]);
//                         ans1.push_back(nums[k]);
//                         sort(ans1.begin(), ans1.end());
//                         break;
//                     }
//                 }
//                 if(!ans1.empty()) {
//                     ans.push_back(ans1);
//                 }
//                 j--;
//             }
//         }
//         sort(ans.begin(), ans.end());
//         ans.erase(unique(ans.begin(), ans.end()), ans.end());
//         return ans;
//     }
// };



class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        int i, j, k;
        for(i = 0; i < nums.size() - 2; i++) {
            if(i>0 && nums[i] == nums[i-1]) {
                continue;
            }
            j = i+1;
            k = nums.size()-1;
            while(j < k) {
                vector<int> ans1;
                int x = nums[i] + nums[j] + nums[k];
                if(x == 0) {
                    ans1.push_back(nums[i]);
                    ans1.push_back(nums[j]);
                    ans1.push_back(nums[k]);
                    sort(ans1.begin(), ans1.end());
                    // break;
                    j++;
                    k--;
                }
                else if(x < 0) {
                    j++;
                }
                else {
                    k--;
                }
                if(!ans1.empty()) {
                    ans.push_back(ans1);
                }
            }
        }
        sort(ans.begin(), ans.end());
        ans.erase(unique(ans.begin(), ans.end()), ans.end());
        return ans;
    }
};