// class Solution {
// public:
//     int mySqrt(int x) {
//         if(x < 2) {
//             return x;
//         }
//         long int k = x/2, i;
//         for(i = 1; i <= k; i++) {
//             if(i*i == x) {
//                 return i;
//             }
//             if(i*i > x) {
//                 break;
//             }
//         }
//         return i-1;
//     }
// };

// class Solution {
// public:
//     int mySqrt(int x) {
//         if(x == 1) {
//             return x;
//         }
//         long int i;
//         for(i = x/2; i >= 0; i/=2) {
//             if(i*i <= x) {
//                 break;
//             }
//         }
//         while(1) {
//             if(i*i > x) {
//                 break;
//             }
//             i++;
//         }
//         return i-1;
//     }
// };

// class Solution {
// public:
//     int mySqrt(int x) {
//         if (x < 2) return x;  // sqrt(0)=0, sqrt(1)=1

//         int left = 1, right = x / 2, ans = 0;
//         while (left <= right) {
//             long long mid = left + (right - left) / 2;
//             long long sq = mid * mid;

//             if (sq == x) return mid;       // perfect square
//             else if (sq < x) {
//                 ans = mid;                 // candidate
//                 left = mid + 1;            // search higher
//             } else {
//                 right = mid - 1;           // search lower
//             }
//         }
//         return ans;
//     }
// };

class Solution {
public:
    int mySqrt(int x) {
        if(x < 2) {
            return x;
        }
        int left = 1, right = x/2, ans;
        while(left <= right) {
            long int mid = (left+right)/2;
            long int sq = mid*mid;
            if(sq == x) {
                return mid;
            }
            else if(sq < x) {
                ans = mid;
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }
        return ans;
    }
};