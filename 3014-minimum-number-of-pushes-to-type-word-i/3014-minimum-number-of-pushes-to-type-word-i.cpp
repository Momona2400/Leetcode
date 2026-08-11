class Solution {
public:
    int minimumPushes(string word) {
        int n = word.length(), sum = 0, j = 1;
        while(n >= 8) {
            sum += 8*j;
            j++;
            n-=8;
        }
        sum += n*j;
        return sum;
    }
};