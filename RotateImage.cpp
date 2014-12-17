#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>> &matrix) {
        int n = matrix.size();
        if (n == 0)
            return;

        // Flip with respect with the antidiagonal
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n - i; ++j) {
                swap(matrix[i][j], matrix[n - 1 - j][n - 1 - i]);
            }
        }

        // Flip with respect with the middle
        for (int i = 0; i < n/2; ++i) {
            for (int j = 0; j < n; ++j) {
                swap(matrix[i][j], matrix[n-1-i][j]);
            }
        }
    }
};

int main()
{
    vector<vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9},
    };

    Solution solver;
    solver.rotate(matrix);
}
