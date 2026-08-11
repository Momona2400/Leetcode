class Solution {
public:
    int jump(vector<int>& nums) {
        vector<vector<int>> adj(nums.size());
        for(int i = 0; i < nums.size() - 1; i++) {
            for(int j = 1; j <= nums[i]; j++) {
                if(i+j < nums.size()) {
                    adj[i].push_back(i+j);
                }
            }
        }
        vector<int> dist(nums.size(), -1);
        queue<int> q;
        q.push(0);
        dist[0] = 0;
        while(!q.empty()) {
            int x = q.front();
            for(int i = 0; i < adj[x].size(); i++) {
                int y = adj[x][i];
                if(dist[y] == -1) {
                    q.push(y);
                    dist[y] = dist[x] + 1;
                }
            }
            q.pop();
        }
        return dist[nums.size() - 1];
    }
};