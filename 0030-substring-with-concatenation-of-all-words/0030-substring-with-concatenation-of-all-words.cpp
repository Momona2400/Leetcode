class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        unordered_map<string, int> um1;
        unordered_map<string, int> um2;
        vector<int> ans;
        for(auto i : words) {
            um1[i]++;
        }
        int k = words[0].length()*words.size();
        for(int i = 0; i < words[0].length(); i++) {
            int start = i;
            for(int end = words[0].length()+start; end <= s.length(); end+=words[0].length()) {
                string temp = s.substr(end-words[0].length(), words[0].length());
                um2[temp]++;
                if(end-start >= k) {
                    if(um1 == um2) {
                        ans.push_back(start);
                    }
                    string temp2 = s.substr(start, words[0].length());
                    um2[temp2]--;
                    if(um2[temp2] == 0) {
                        um2.erase(temp2);
                    }
                    start+=words[0].length();
                }
            }
            um2.clear();
        }
        return ans;
    }
};