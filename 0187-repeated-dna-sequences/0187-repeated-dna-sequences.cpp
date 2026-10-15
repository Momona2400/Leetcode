// class Solution {
// public:
//     vector<string> findRepeatedDnaSequences(string s) {
//         unordered_map<string, int> um;
//         int start = 0;
//         for(int end = 9; end < s.length(); end++) {
//             um[s.substr(end-9, 10)]++;
//         }
//         vector<string> ans;
//         for(auto i : um) {
//             if(i.second > 1) {
//                 ans.push_back(i.first);
//             }
//         }
//         return ans;
//     }
// };

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> ans;
        unordered_map<string, int> um;
        int start = 0;
        string temp = s.substr(0, 10);
        um[temp] = 1;
        for(int end = 10; end < s.length(); end++) {
            temp.erase(0, 1);
            temp+=s[end];
            // if(um.find(temp) == um.end()) {
                um[temp]++;
            // }
            if(um[temp] == 2) {
                // if(find(ans.begin(), ans.end(), temp) == ans.end()) {
                    ans.push_back(temp);
                // }
            }
        }
        return ans;
    }
};


// class Solution {
// public:
//     vector<string> findRepeatedDnaSequences(string s) {
//         vector<string> ans;
//         if (s.length() < 10) return ans;

//         unordered_map<string, int> um;

//         for (int i = 0; i <= s.length() - 10; i++) {
//             string temp = s.substr(i, 10);

//             um[temp]++;

//             if (um[temp] == 2) {
//                 ans.push_back(temp);
//             }
//         }

//         return ans;
//     }
// };
