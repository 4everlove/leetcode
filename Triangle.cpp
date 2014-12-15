#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int>> &triangle) {
        vector<vector<int>> solution(triangle.size());
        // Construct the solution from bottom up
        for (int i = 0; i < triangle.size(); ++i) {
            vector<int> &solution_row = solution[i];
            solution_row.resize(triangle[i].size(), 0);
            int j = 0;
            solution_row[j] = triangle[i][j] + (i == 0 ? 0 : solution[i - 1][j]);
            for (j = 1; j < triangle[i].size() - 1; ++j) {
                int a = (i == 0 ? 0 : solution[i - 1][j]);
                int b = (i == 0 ? 0 : solution[i - 1][j - 1]);
                solution_row[j] = triangle[i][j] + (a < b ? a : b);
            }
            solution_row[j] = triangle[i][j] + (i == 0 ? 0 : solution[i - 1][j - 1]);
        }
        if (triangle.size() == 0)
            return 0;
        else
            return *min_element(solution.back().begin(), solution.back().end());
    }
};

int main()
{
    vector<vector<int>> triangle = 
    {
        {2},
        {3, 4},
        {6, 5, 7},
        {4, 1, 8, 3},
    };

    Solution solver;
    cout << "The minimum path is: " << solver.minimumTotal(triangle) << std::endl;
}
