class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        int N = logs.size();
        int maxele = INT_MIN;
        for(int i = 0; i < N; i++) {
            maxele = max(maxele, logs[i][1]);
        }
        int minele = INT_MAX;
        for(int i = 0; i < N; i++) {
            minele = min(minele, logs[i][0]);
        }
        int size = maxele-minele+1;
        vector<int> nums2(size);
        for(int i = 0; i < N; i++) {
            nums2[logs[i][0]-minele]++;
            nums2[logs[i][1]-minele]--;
        }
        vector<int> prefixsum(size);
        prefixsum[0] = nums2[0];
        for(int i = 1; i < size; i++) {
            prefixsum[i] = prefixsum[i-1] + nums2[i];
        }
        int ans = INT_MIN, ans2 = 0;
        for(int i = 0; i < size; i++) {
            if(ans < prefixsum[i]) {
                ans= prefixsum[i];
                ans2 = i+minele;
            }
        }
        return ans2;
    }
};