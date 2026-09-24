class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char, int> um1;
        unordered_map<char, int> um2;
        for(char i : s1) {
            um1[i]++;
        }
        int k = s1.length();
        int start = 0;
        for(int end = 0; end < s2.length(); end++) {
            um2[s2[end]]++;
            if(end - start + 1 == k) {
                if(um1 == um2) {
                    return true;
                }
                um2[s2[start]]--;
                if(um2[s2[start]] == 0) {
                    um2.erase(s2[start]);
                }
                start++;
            }
        }
        return false;
    }
};