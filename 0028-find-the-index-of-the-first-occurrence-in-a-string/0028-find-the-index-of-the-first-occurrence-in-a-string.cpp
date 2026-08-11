// class Solution {
// public:
//     int strStr(string haystack, string needle) {
//         for(int i = 0; i < haystack.size(); i++) {
//             if(haystack[i] != needle[0]) {
//                 continue;
//             }
//             int j, k = i;
//             for(j = 0; j < needle.size(); j++) {
//                 if(needle[j] != haystack[k]) {
//                     break;
//                 }
//                 k++;
//             }
//             if(j == needle.size()) {
//                 return i;
//             }
//         }
//         return -1;
//     }
// };

// class Solution {
// public:
//     int strStr(string haystack, string needle) {
//         int i = 0, j = 0, k;
//         while(haystack.size() - i >= needle.size() && i < haystack.size()) {
//             while(haystack[i] != needle[j] && i < haystack.size()) {
//             i++;
//             }
//             k = i, j = 0;
//             while(haystack[i] == needle[j] && j < needle.size()) {
//                 j++;
//                 i++;
//             }
//             if(j == needle.size()) {
//                 return k;
//             }
//         }
//         return -1;
//     }
// };

class Solution {
public:
    int strStr(string haystack, string needle) {
        if(haystack.size() < needle.size()) {
            return -1;
        }
        int i = 0;
        while(i <= haystack.size() - needle.size()) {
            if(haystack[i] != needle[0]) {
                i++;
            }
            else {
                int j = 0;
                while(j < needle.size()) {
                    if(haystack[i] != needle[j]) {
                        break;
                    }
                    i++;
                    j++;
                }
                if(j == needle.size()) {
                    return i - needle.size();
                }
                else {
                    i = i - j + 1;
                }
            }
        }
        return -1;
    }
};