class Solution {
public:
    int lengthOfLastWord(string s) {
        int count = 0;
        for(int i = s.size() - 1; i >= 0; i--) {
            if(s[i] == ' ' && s[i+1] != ' ' && i < s.size() - 1) {
                return count;
            }
            else if(s[i] == ' ') {
                continue;
            }
            else {
                count++;
            }
        }
        return count;
    }
};