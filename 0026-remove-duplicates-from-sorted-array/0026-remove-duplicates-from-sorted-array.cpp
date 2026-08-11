class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // // int k = 0;
        // for(int i = 0; i < nums.size()-1; i++) {
        //     if(nums[i] == nums[i+1]) {
        //         nums.erase(nums.begin()+i);
        //         i--;
        //     }
        //     // else {
        //     //     k++;
        //     // }
        // }
        // // return k;,
        // return nums.size();

        int k = 1;
        for(int i = 1; i < nums.size(); i++) {
            if(nums[i] != nums[i-1]) {
                nums[k] = nums[i];
                k++;
            }
        }
        return k;
    }
};