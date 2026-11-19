class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<int> start(intervals.size()), end(intervals.size());
        for(int i = 0; i < intervals.size(); i++) {
            start[i] = intervals[i][0];
            end[i] = intervals[i][1];
        }
        sort(start.begin(), start.end());
        sort(end.begin(), end.end());
        vector<int> start1, end1;
        int i = 1, j = 0;
        start1.push_back(start[0]);
        while(i < start.size() && j < end.size()) {
            if(start[i] > end[j]) {
                end1.push_back(end[j]);
                start1.push_back(start[i]);
            }
            i++;
            j++;
        }
        end1.push_back(end[end.size()-1]);
        vector<vector<int>> ans;
        for(int i = 0; i < start1.size(); i++) {
            ans.push_back({start1[i], end1[i]});
        }
        return ans;
    }
};