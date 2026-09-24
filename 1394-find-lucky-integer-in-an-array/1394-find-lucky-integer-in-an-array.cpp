class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map<int, int> um;
        for(int i = 0; i < arr.size(); i++) {
        um[arr[i]]++;
        }
        vector<pair<int, int>> lucky;
        for(auto i : um) {
            if(i.first == i.second) {
                lucky.push_back(i);
            }
        }
        if(lucky.empty()) {
            return -1;
        }
        sort(lucky.begin(), lucky.end());
        return lucky.back().first;
    }
};