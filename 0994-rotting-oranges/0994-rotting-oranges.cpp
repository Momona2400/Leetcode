class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        vector<vector<int>> status(grid.size(), vector<int> (grid[0].size(), 0));
        queue<pair<int,int>> q;
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[i].size(); j++) {
                int o = grid[i][j];
                if(o == 2) {
                    status[i][j] = 0;
                    q.push(make_pair(i, j));
                }
            }
        }
        pair<int, int> m;
        m = make_pair(0, 0);
        while(!q.empty()) {
            pair<int, int> o;
            o = q.front();
            int a = o.first;
            int b = o.second;
            if(a > 0) {
                if(grid[a-1][b] == 1) {
                    grid[a-1][b] = 2;
                    q.push(make_pair(a-1, b));
                    status[a-1][b] = status[a][b] + 1;
                }
            }
            if(b > 0) {
                if(grid[a][b-1] == 1) {
                    grid[a][b-1] = 2;
                    q.push(make_pair(a, b-1));
                    status[a][b-1] = status[a][b] + 1;
                }
            }
            if(a < grid.size() - 1) {
                if(grid[a+1][b] == 1) {
                    grid[a+1][b] = 2;
                    q.push(make_pair(a+1, b));
                    status[a+1][b] = status[a][b] + 1;
                }
            }
            if(b < grid[0].size() - 1) {
                if(grid[a][b+1] == 1) {
                    grid[a][b+1] = 2;
                    q.push(make_pair(a, b+1));
                    status[a][b+1] = status[a][b] + 1;
                }
            }
            if(q.front() == q.back()) {
                m = q.front();
            }
            q.pop();
        }
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[i].size(); j++) {
                int o = grid[i][j];
                if(o == 1) {
                    return -1;
                }
            }
        }
        return status[m.first][m.second];
    }
};