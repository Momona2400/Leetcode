// class Solution {
// public:
//     string smallestPalindrome(string s) {
//         string t = "";
//         int n = s.length();
//         if(n%2 == 0) {
//             sort(s.begin(), s.end());
//             for(int i = 0; i < n; i+=2) {
//                 t += s[i];
//             }
//             for(int i = n-1; i >= 0; i-=2) {
//                 t += s[i];
//             }
//         }
//         else {
//             int c = n/2;
//             char ch = s[c];
//             s.erase(c, 1);
//             sort(s.begin(), s.end());
//             for(int i = 0; i < n-1; i+=2) {
//                 t += s[i];
//             }
//             t += ch;
//             for(int i = n-2; i >= 0; i-=2) {
//                 t += s[i];
//             }
//         }
//         return t;
//     }
// };


class Solution {
public:
    string smallestPalindrome(string s) {
        int freq[26] = {0};
        for(int i = 0; i < s.length(); i++) {
            char ch = s[i];
            freq[ch-97]++;
        }
        string temp = "";
        for(int i = 0; i < 26; i++) {
            for(int j = 0; j < freq[i]/2; j++) {
                temp += char(i+97);
            }
            freq[i] -= (freq[i]/2)*2;
        }
        string ans = "";
        ans += temp;
        for(int i = 0; i < 26; i++) {
            if(freq[i] > 0) {
                ans += char(i+97);
            }
        }
        reverse(temp.begin(), temp.end());
        ans += temp;
        return ans;
    }
};