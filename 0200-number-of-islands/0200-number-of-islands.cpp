class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int noi = 0;
        queue<pair<int, int>> q;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (grid[i][j] == '1') {
                    q.push(make_pair(i, j));
                    while (!q.empty()) {
                        pair<int, int> x;
                        x = q.front();
                        int m = x.first;
                        int n = x.second;
                        if (m > 0) {
                            if (grid[m - 1][n] == '1') {
                                grid[m - 1][n] = '0';
                                q.push(make_pair(m - 1, n));
                            }
                        }
                        if (n > 0) {
                            if (grid[m][n - 1] == '1') {
                                grid[m][n - 1] = '0';
                                q.push(make_pair(m, n - 1));
                            }
                        }
                        if (m < grid.size() - 1) {
                            if (grid[m + 1][n] == '1') {
                                grid[m + 1][n] = '0';
                                q.push(make_pair(m + 1, n));
                            }
                        }
                        if (n < grid[m].size() - 1) {
                            if (grid[m][n + 1] == '1') {
                                grid[m][n + 1] = '0';
                                q.push(make_pair(m, n + 1));
                            }
                        }
                        q.pop();
                    }
                    noi++;
                }
            }
        }
        return noi;
    }
};