class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        int maxele = INT_MIN;
        for(int i = 0; i < trips.size(); i++) {
            maxele = max(trips[i][2], maxele);
        }
        vector<int> prefixsum(maxele+1, 0);
        for(int i = 0; i < trips.size(); i++) {
            prefixsum[trips[i][1]] += trips[i][0];
            prefixsum[trips[i][2]] -= trips[i][0];
        }
        for(int i = 1; i < prefixsum.size(); i++) {
            prefixsum[i] += prefixsum[i-1];
        }
        int maxele2 = INT_MIN;
        for(int i = 0; i < prefixsum.size(); i++) {
            maxele2 = max(maxele2, prefixsum[i]);
        }
        if(maxele2 <= capacity) {
            return true;
        }
        return false;
    }
};