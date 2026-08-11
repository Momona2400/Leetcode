class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0) {
            return false;
        }
        // if(x==0) {
        //     return true;
        // }
        int count = 0, n = x, m = x;
        while(m != 0) {
            count++;
            m/=10;
        }
        if(count < 2) {
            return true;
        }
        int rev[count];
        int y = count/2;
        for(int i = 0; i < count; i++) {
            rev[i] = n%10;
            n/=10;
        }
        for(int i = 0; i < y; i++) {
            if(rev[i] != rev[count-i-1]) {
                return false;
            }
        }
        return true;
    }
};


//just use long long int in place of int in the normal int rev soln