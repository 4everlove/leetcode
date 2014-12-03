#include <iostream>

// This algorithm comes from Wikipedia: 
// http://en.wikipedia.org/wiki/Division_algorithm#Integer_division_.28unsigned.29_with_remainder
class Solution {
public:
    int divide(int dividend, int divisor) {
        if (divisor == 0)
            throw;
    
        unsigned int N = abs(dividend), D = abs(divisor), n = 8 * sizeof(int), Q = 0, R = 0;
        for (int i = n - 1; i >= 0; i--) {
            R = R << 1;
            R = R | (1 & (N >> i));
            if (R >= D) {
                R = R - D;
                Q = Q | (1 << i);
            }
        }

        if ((dividend >= 0 && divisor > 0) || (dividend < 0 && divisor < 0))
            return Q;
        else
           return -(int)Q; // 24 / -7 in C++ is not the same as what python will give
    }

    unsigned int abs(int value) {
        return value >= 0 ? value : -value;
    }
};

int main()
{
    Solution solver;
    std::cout << "14 / 7: " << (solver.divide(14, 7) == 14 / 7 ? "CHECK" : "WRONG") << std::endl
              << "26 / 3: " << (solver.divide(26, 3) == 26 / 3 ? "CHECK" : "WRONG")<< std::endl
              << "-14 / -7: " << (solver.divide(-14, -7) == -14 / -7 ? "CHECK" : "WRONG") << std::endl
              << "-26 / -3: " << (solver.divide(-26, -3) == -26 / -3 ? "CHECK" : "WRONG") << std::endl
              << "24 / -7: " << (solver.divide(24, -7) == 24 / -7 ? "CHECK" : "WRONG") << std::endl
              << "1 / -1: " << (solver.divide(1, -1) == 1 / -1 ? "CHECK" : "WRONG") << std::endl
              << "-24 / 7: " << (solver.divide(-24, 7)  == -24 / 7 ? "CHECK" : "WRONG") << std::endl
              << "2147483647 / 1: " << (solver.divide(2147483647, 1) == 2147483647 / 1 ? "CHECK" : "WRONG")<< std::endl;
}
