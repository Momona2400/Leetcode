class Solution {
public:
    string reverseWords(string s) {
        vector<string> t;
        stringstream ss(s);
        string k;
        while(ss >> k) {
            t.push_back(k);
        }
        string f;
        for(int i = t.size() - 1; i > 0; i--) {
            f += t[i];
            f += " ";
        }
        f += t[0];
        return f;
    }
};