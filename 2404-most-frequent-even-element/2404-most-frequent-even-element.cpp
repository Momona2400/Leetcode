class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        unordered_map<int, int> um;
        for(int i = 0; i < nums.size(); i++) {
            um[nums[i]]++;
        }
        vector<pair<int, int>> evenele;
        for(auto i : um) {
            if(i.first%2 == 0) {
                evenele.push_back(i);
            }
        }
        if(evenele.empty()) {
            return -1;
        }
        pair<int, int> maxe = {evenele.begin()->first, evenele.begin()->second};
        for(auto i : evenele) {
            if(i.second > maxe.second) {
                maxe.first = i.first;
                maxe.second = i.second;
            }
            else if(i.second == maxe.second) {
                maxe.first = min(i.first, maxe.first);
            }
        }
        return maxe.first;
    }
};