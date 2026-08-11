class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int nop = 0;
        queue<int> q;
        for (int i = 0; i < isConnected.size(); i++) {
            for (int j = 0; j < isConnected[i].size(); j++) {
                if (isConnected[i][j] == 1) {
                    q.push(i);
                    q.push(j);
                    while (!q.empty()) {
                        int x = q.front();
                        for(int k = 0; k < isConnected.size(); k++) {
                            if(isConnected[k][x] == 1) {
                                q.push(k);
                            }
                            isConnected[k][x] = 0;
                        }
                        q.pop();
                    }
                    nop++;
                }
            }
        }
        return nop;
    }
};