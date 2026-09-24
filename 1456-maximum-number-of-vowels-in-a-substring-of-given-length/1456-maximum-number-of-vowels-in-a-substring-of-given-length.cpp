class Solution {
public:

    static bool isVowel(char ch) {
        if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
            return true;
        }
        return false;
    }

    int maxVowels(string s, int k) {
        int start = 0, count = 0, maxcount = 0;
        for(int end = 0; end < s.length(); end++) {
            if(isVowel(s[end])) {
                count++;
            }
            if(end-start+1 >= k) {
                maxcount = max(maxcount, count);
                isVowel(s[start])?count--:count;
                start++;
            }
        }
        return maxcount;
    }
};