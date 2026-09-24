class Solution {
public:
    int countKDifference(vector<int>& arr, int K) {
        unordered_map<int, int> um;
        int count = 0;
        for(int i = 0; i < arr.size(); i++) {
            if(K!= 0) {
                int diff1 = K+arr[i];
                int diff2 = arr[i]-K;
                count+=um[diff1];
                count+=um[diff2];
            }
            else {
                count+=um[arr[i]];
            }
            um[arr[i]]++;
        }
        return count;
    }
};