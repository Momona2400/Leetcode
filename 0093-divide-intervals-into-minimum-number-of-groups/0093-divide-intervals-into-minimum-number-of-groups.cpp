class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        vector<int> arr(intervals.size()), dep(intervals.size());
        for(int i = 0; i < intervals.size(); i++) {
            arr[i] = intervals[i][0];
        }
        for(int i = 0; i < intervals.size(); i++) {
            dep[i] = intervals[i][1];
        }
        sort(arr.begin(), arr.end());
        sort(dep.begin(), dep.end());
        int i = 0, j = 0, s = 0, strip = INT_MIN;
        while(i < arr.size() && j < dep.size()) {
            if(arr[i] > dep[j]) {
                j++;
                s--;
            }
            else {
                i++;
                s++;
            }
            strip = max(strip, s);
        }
        return strip;
    }
};