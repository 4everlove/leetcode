#include <vector>
using namespace std;

// Recursive version

class Solution {
public:
    vector<vector<int> > permute(vector<int> &num)
    {
        vector<vector<int>> permutations;
        stack.resize(num.size(), 0);
        visit.resize(num.size(), false);
        
        do_permute(num, 0, permutations);
        return permutations;
    }
    
    void do_permute(const vector<int> &num, int depth, vector<vector<int>> &result)
    {
        if (depth == num.size()) {
            result.push_back(stack);
            return;
        }
    
        for (int i = 0; i < num.size(); ++i) {
            if (!visit[i]) {
                visit[i] = true;
                stack[depth] = num[i];
                do_permute(num, depth + 1, result);
                visit[i] = false; // we need to restore the visit array.
            }
        }
    }

private:
    vector<int> stack;
    vector<bool> visit;
};

