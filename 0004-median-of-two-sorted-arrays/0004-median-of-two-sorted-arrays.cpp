class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        int i = 0, j = 0;
        vector<int> arr(m+n);
        while(i < m && j < n) {
            if(nums1[i] < nums2[j]) {
                arr[i+j] = nums1[i];
                i++;
            }
            else {
                arr[i+j] = nums2[j];
                j++;
            }
        }
        while(i < m) {
            arr[i+j] = nums1[i];
            i++;
        }
        while(j < n) {
            arr[i+j] = nums2[j];
            j++;
        }
        int t = m+n;
        if(t%2 == 0) {
            return (arr[t/2] + arr[(t/2)-1])/2.0;
        }
        else {
            return arr[t/2];
        }
    }
};