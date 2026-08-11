class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        // int k = 0;
        // for(int i = 0; i < nums.size()-1; i++) {
        //     while(nums[k] != val && k < nums.size()) {
        //         k++;
        //     }
        //     if(nums[i] == val && nums[i+1] != val) {
        //         nums[k] = nums[i+1];
        //         k++;
        //     }
        // }
        // return k;

        int k = 0; 
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] != val) {
                nums[k] = nums[i];
                k++;
            }
        }
        return k;
    }
};