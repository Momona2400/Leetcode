class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        int start = 0, maxlen = 0;
        unordered_map<int, int> um;
        for(int end = 0; end < n; end++) {
            um[fruits[end]]++;
            while(um.size() > 2) {
                um[fruits[start]]--;
                if(um[fruits[start]] == 0) {
                    um.erase(fruits[start]);
                }
                start++;
            }
            maxlen = max(maxlen, end-start+1);
        }
        return maxlen;
    }
};