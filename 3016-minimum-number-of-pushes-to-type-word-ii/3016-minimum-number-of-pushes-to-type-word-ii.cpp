class Solution {
public:
    int minimumPushes(string word) {
        int sum = 0;
        int arr[26] = {0};
        for(int i = 0; i < word.length(); i++) {
            arr[word[i]- 97]++;
        }
        int maxx, j = 0, q;
        do {
            maxx = 0;
            for(int i = 0; i < 26; i++) {
                if(maxx < arr[i]) {
                    maxx = arr[i];
                    q = i;
                }
            }
            arr[q] = 0;
            sum += maxx*((j/8) + 1);
            j++;
        } while(maxx != 0);
        return sum;
    }
};