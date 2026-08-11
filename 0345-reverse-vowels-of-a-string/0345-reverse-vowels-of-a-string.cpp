class Solution {
public:

    bool isVowel(char c) {
        if(c == 'a' || c == 'A' || c == 'e' || c == 'E' || c == 'o' || c == 'O' || c == 'u' || c == 'U' || c == 'i' || c == 'I')
        return true;
        else
        return 
        false;
    }

    string reverseVowels(string s) {
        int d = size(s), i;
        int a = 0, b = d-1;
        // for(i = 0; i < d; i++) {
        //     if(isVowel(s[i]))
        //     break;
        // }
        // if(i == d) {
        //     return s;
        // }
        while(a<b) {
            while(!isVowel(s[a]) && a<b) {
                a++;
            }
            while(!isVowel(s[b]) && a<b) {
                b--;
            }
            swap(s[a], s[b]);
            a++;
            b--;
        }
        return s;
    }
};