#include <vector>
#include <algorithm>
using std::vector;
using std::min;

class Solution {
public:
    int minPathSum(vector<vector<int> > &grid) {
        if (grid.size() == 0)
            return 0;

        vector<vector<int>> path(grid.size(), vector<int>(grid[0].size(), 0));
        path[0][0] = grid[0][0];
        for (int i = 1; i < grid.size(); ++i)
            path[i][0] = grid[i][0] + path[i - 1][0];
        for (int j = 1; j < grid[0].size(); ++j)
            path[0][j] = grid[0][j] + path[0][j - 1];
        for (int i = 1; i < grid.size(); ++i) {
            for (int j = 1; j < grid[0].size(); ++j) {
                path[i][j] = grid[i][j] + min(path[i-1][j], path[i][j-1]);
            }
        }
    
        return path[grid.size() - 1][grid[0].size() - 1];
    }
};
