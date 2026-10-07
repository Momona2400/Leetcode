class Solution {
public:
    int longestOnes(vector<int>& arr, int K) {
        int start = 0, k = K, maxwin = 0;
        for(int end = 0; end < arr.size(); end++) {
            if(arr[end] == 0 && k == 0) {
                while(arr[start] != 0) {
                start++;
                }
                start++;
            }
            else if(arr[end] == 0 && k!= 0) {
                k--;
            }
            maxwin = max(maxwin, end-start+1);
        }
        return maxwin;
    }
};