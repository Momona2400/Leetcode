class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        // if(s.length() < 10) {
        //     return 
        // }
        unordered_map<string, int> um;
        int start = 0;
        for(int end = 9; end < s.length(); end++) {
            um[s.substr(end-9, 10)]++;
        }
        vector<string> ans;
        for(auto i : um) {
            if(i.second > 1) {
                ans.push_back(i.first);
            }
        }
        return ans;
    }
};