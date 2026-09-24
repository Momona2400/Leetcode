class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        unordered_map<char, int> um1;
        unordered_map<char, int> um2;
        vector<int> ans;
        for(char i : p) {
            um1[i]++;
        }
        int k = p.length();
        int start = 0;
        for(int end = 0; end < s.length(); end++) {
            um2[s[end]]++;
            if(end - start + 1 == k) {
                if(um1 == um2) {
                    ans.push_back(start);
                }
                um2[s[start]]--;
                if(um2[s[start]] == 0) {
                    um2.erase(s[start]);
                }
                start++;
            }
        }
        return ans;
    }
};