// class Solution {
// public:
//     string longestPalindrome(string s) {
//         int n = s.length(), a;
//         int sum1 = 0, p = 0;
//         for(int i = 0; i < n; i++) {
//             int sum2 = 0, sum3 = 0;
//             for(int j = i-1, k = i+1; j >= 0 && k < n; j--, k++) {
//                 if(s[j] == s[k]) {
//                     sum2++;
//                     a = i;
//                 }
//             }
//             sum2 = 2*sum1 + 1;
//             for(int j = i, k = i+1; j >= 0 && k < n; j--, k++) {
//                 if(s[j] == s[k]) {
//                     sum3++;
//                 }
//             }
//             sum3 = 2*sum3;
//             if(sum2 < sum3) {
//                 sum2 = sum3;
//                 p = 1;
//             }
//             if(sum1 < sum2) {
//                 sum1 = sum2;
//                 p = 1;
//                 a = i;
//             }
//             else {
//                 p = 0;
//             }
//         }
//         if(p == 0) {
//             int q = a - sum1, l = 2*sum1 + 1;
//             return s.substr(q, l);
//         }
//         else {
//             int q = a - sum1 + 1, l = 2*sum1;
//             return s.substr(q, l);
//         }
//     }
// };



class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        int sum1, sum2, sum3, max = 0, idx;
        for(int i = 0; i < n; i++) {
            sum1 = 1, sum2 = 0;
            for(int j = i-1, k = i+1; j >= 0 && k < n; j--, k++) {
                if(s[j] == s[k]) {
                    sum1+=2;
                }
                else {
                    break;
                }
            }
            for(int j = i, k = i+1; j >= 0 && k < n; j--, k++) {
                if(s[j] == s[k]) {
                    sum2+=2;
                }
                else {
                    break;
                }
            }
            if(sum1 < sum2) {
                sum3 = sum2;
            }
            else {
                sum3 = sum1;
            }
            if(max < sum3) {
                max = sum3;
                idx = i;
            }
        }
        sum1 = 1, sum2 = 0;
        for(int j = idx-1, k = idx+1; j >= 0 && k < n; j--, k++) {
            if(s[j] == s[k]) {
                sum1+=2;
            }
            else {
                break;
            }
        }
        for(int j = idx, k = idx+1; j >= 0 && k < n; j--, k++) {
            if(s[j] == s[k]) {
                sum2+=2;
            }
            else {
                break;
            }
        }
        // cout<<sum1<<endl<<sum2<<endl;
        if(sum1 < sum2) {
            return s.substr((idx-(sum2/2)+1), sum2);
        }
        else {
            return s.substr((idx-(sum1/2)), sum1);
        }
    }
};