class Solution {
public:
    string minWindow(string s, string t) {
        if(s.length() < t.length()) {
            return "";
        }
        unordered_map<char, int> um1;
        unordered_map<char, int> um2;
        int ans1 = -1, ans2 = -1;
        for(auto i : t) {
            um1[i]++;
            um2[i] = 0;
        }
        int start = 0, minsize = INT_MAX, count = 0;
        for(int end = 0; end < s.length(); end++) {
            if(um1.find(s[end]) != um1.end()) {
                um2[s[end]]++;
                if (um2[s[end]] <= um1[s[end]]) {
                    count++;
                }
            }
            // int i;
            // for(i = 0; i < t.size(); i++) {
            //     if(um1[t[i]] > um2[t[i]]) {
            //         break;
            //     }
            // }
            while(count == t.size()) {
                if(minsize>end-start+1) {
                    ans1 = start;
                    ans2 = end;
                    minsize = end-start+1;
                 }
                if(um2.find(s[start]) != um2.end()) {
                    if (um2[s[start]] <= um1[s[start]]) {
                        count--;
                    }
                    um2[s[start]]--;
                }
                start++;
                // for(i = 0; i < t.length(); i++) {
                //     if(um1[t[i]] > um2[t[i]]) {
                //         break;
                //     }
                // }
            }
        }
        if(ans1 == -1 && ans2 == -1) {
            return "";
        }
        return s.substr(ans1, ans2-ans1+1);
    }
};