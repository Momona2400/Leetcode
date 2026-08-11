class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if(grid[0][0] == 1 || grid[grid.size()-1][grid[0].size()-1] == 1) {
            return -1;
        }
        vector<vector<int>> status(grid.size(), vector<int> (grid[0].size(), -1));
        queue<pair<int, int>> q;
        status[0][0] = 1;
        q.push({0, 0});
        int a, b;
        pair<int, int> p;
        while(!q.empty()) {
            p = q.front();
            a = p.first;
            b = p.second;
            if(a == grid.size() - 1 && b == grid[0].size() - 1) {
                break;
            }
            //up
            if(a-1 >= 0) {
                if(grid[a-1][b] == 0) {
                    q.push({a-1,b});
                    status[a-1][b] = status[a][b] + 1;
                    grid[a-1][b] = 1;
                }
            }
            //down
            if(a+1 < grid.size()) {
                if(grid[a+1][b] == 0) {
                    q.push({a+1,b});
                    status[a+1][b] = status[a][b] + 1;
                    grid[a+1][b] = 1;
                }
            }
            //left
            if(b-1 >= 0) {
                if(grid[a][b-1] == 0) {
                    q.push({a,b-1});
                    status[a][b-1] = status[a][b] + 1;
                    grid[a][b-1] = 1;
                }
            }
            //right
            if(b+1 < grid[0].size()) {
                if(grid[a][b+1] == 0) {
                    q.push({a,b+1});
                    status[a][b+1] = status[a][b] + 1;
                    grid[a][b+1] = 1;
                }
            }
            //up right
            if(a-1 >= 0 && b+1 < grid[0].size()) {
                if(grid[a-1][b+1] == 0) {
                    q.push({a-1,b+1});
                    status[a-1][b+1] = status[a][b] + 1;
                    grid[a-1][b+1] = 1;
                }
            }
            //right down
            if(b+1 < grid[0].size() && a+1 < grid.size()) {
                if(grid[a+1][b+1] == 0) {
                    q.push({a+1,b+1});
                    status[a+1][b+1] = status[a][b] + 1;
                    grid[a+1][b+1] = 1;
                }
            }
            //up left
            if(a-1 >= 0 && b-1 >= 0) {
                if(grid[a-1][b-1] == 0) {
                    q.push({a-1,b-1});
                    status[a-1][b-1] = status[a][b] + 1;
                    grid[a-1][b-1] = 1;
                }
            }
            //down left
            if(a+1 < grid.size() && b-1 >= 0) {
                if(grid[a+1][b-1] == 0) {
                    q.push({a+1,b-1});
                    status[a+1][b-1] = status[a][b] + 1;
                    grid[a+1][b-1] = 1;
                }
            }
            q.pop();
        }
        if(a == grid.size() - 1 && b == grid[0].size() - 1) {
            return status[a][b];
        }
        else {
            return -1;
        }
    }
};