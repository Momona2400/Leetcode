class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> result(nums1.size());
        for(int i = 0; i < nums1.size(); i++) {
            for(int j = 0; j < nums2.size(); j++) {
                if(nums1[i] == nums2[j]) {
                    if(j == nums2.size()) {
                        result[i] = -1;
                        break;
                    }
                    int k = nums2[j];
                    j++;
                    while(j < nums2.size()) {
                        if(nums2[j] < k) {
                            j++;
                        }
                        else {
                            break;
                        }
                    }
                    if(j != nums2.size()) {
                        result[i] = nums2[j];
                        break;
                    }
                    result[i] = -1;
                    break;
                }
            }
        }
        return result;
    }
};