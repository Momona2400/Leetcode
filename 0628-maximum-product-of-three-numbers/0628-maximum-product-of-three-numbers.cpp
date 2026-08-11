// class Solution {
// public:
//     int maximumProduct(vector<int>& nums) {
//         int m1 = 0, m2, m3;
//         int n = nums.size();
//         for(int i = 0; i < n; i++) {
//             if(nums[m1] < nums[i]) {
//                 m1 = i;
//             }
//         }
//         for(int i = 0; i < n; i++) {
//             if(m1 != i) {
//                 m2 = i;
//                 break;
//             }
//         }
//         for(int i = 0; i < n; i++) {
//             if(nums[m2] < nums[i] && i != m1) {
//                 m2 = i;
//             }
//         }
//         for(int i = 0; i < n; i++) {
//             if(m1 != i && m2 != i) {
//                 m3 = i;
//                 break;
//             }
//         }
//         for(int i = 0; i < n; i++) {
//             if(nums[m3] < nums[i] && i != m1 && i != m2) {
//                 m3 = i;
//             }
//         }
//         return nums[m1]*nums[m2]*nums[m3];
//     }
// };



// class Solution {
// public:
//     int maximumProduct(vector<int>& nums) {
//         int n = nums.size(), temp;
//         sort(nums.begin(), nums.end());
//         if(nums[0] < 0 && nums[1] < 0) {
//             int a = nums[0]*nums[1], b = nums[n-1]*nums[n-2];
//             if(a > b) {
//                 return a*nums[n-1];
//             }
//         }
//         int c = nums[n-1]*nums[n-2]*nums[n-3];
//         return c;
//     }
// };


class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int a = nums[0]*nums[1]*nums[n-1], b = nums[n-3]*nums[n-2]*nums[n-1];
        return max(a, b);
    }
};