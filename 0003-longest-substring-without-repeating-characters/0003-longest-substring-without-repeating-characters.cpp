class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> um;
        int start = 0, ans = 0;
        for(int end = 0; end < s.length(); end++) {
            um[s[end]]++;
            if(um[s[end]] > 1) {
                int idx = s.find(s[end], start);
                while(start <= idx) {
                    um[s[start]]--;
                    if(um[s[start]] == 0) {
                        um.erase(s[start]);
                    }
                    start++;
                }
            }
            ans = max(ans, end-start+1);
        }
        return ans;
    }
};