class Solution {
public:
    void reverseString(vector<char>& s) {
        for(int i = 0 ; i < size(s)/2; i++) {
            int a = s[i];
            s[i] = s[size(s)-i-1];
            s[size(s)-i-1] = a;
        }
    }
};