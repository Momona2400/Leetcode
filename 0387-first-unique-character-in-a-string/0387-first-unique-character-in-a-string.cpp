class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> freq(26, 0);
        for(int i = 0; i < s.length(); i++) {
            char ch = s[i];
            freq[ch-'a']++;
        }
        string single = "";
        for(int i = 0; i < 26; i++) {
            if(freq[i] == 1) {
                single+=(i+'a');
            }
        }
        for(int i = 0; i < s.length(); i++) {
            char ch = s[i];
            if(single.find(ch) != string::npos) {
                return i;
            }
        }
        return -1;
    }
};