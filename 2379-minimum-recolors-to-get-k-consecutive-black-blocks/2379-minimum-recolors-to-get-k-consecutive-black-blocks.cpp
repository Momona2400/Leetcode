class Solution {
public:
    int minimumRecolors(string blocks, int K) {
        int start = 0, count = 0, maxcount = 0; 
        for(int end = 0; end < blocks.length(); end++) {
            if(blocks[end] == 'B') {
                count++;
            }
            maxcount = max(maxcount, count);
            if(end-start+1 >= K) {
                if(blocks[start] == 'B') {
                    count--;
                }
                start++;
            }
        }
        return K - maxcount;
    }
};