class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int K, int T) {
        int start = 0, sum = 0, count = 0;
        for(int end = 0; end < arr.size(); end++) {
            sum+=arr[end];
            int length = end - start + 1;
            if(length == K) {
                int avg = sum/K;
                if(sum >= K * T) {
                    count++;
                }
                sum -= arr[start];
                start++;
            }
        }
        return count;
    }
};