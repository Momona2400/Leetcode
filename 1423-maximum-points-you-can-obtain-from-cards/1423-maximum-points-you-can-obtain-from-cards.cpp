class Solution {
public:
    int maxScore(vector<int>& cardPoints, int K) {
        int k = cardPoints.size() - K, totalsum = 0;
        for(int i = 0; i < cardPoints.size(); i++) {
            totalsum+=cardPoints[i];
        }
        if(k == 0) {
            return totalsum;
        }
        int start = 0, sum = 0, maxsum = 0;
        for(int end =  0; end < cardPoints.size(); end++) {
            sum+= cardPoints[end];
            if(end-start+1 >= k) {
                maxsum = max(maxsum, totalsum-sum);
                sum-=cardPoints[start];
                start++;
            }
        }
        return maxsum;
    }
};