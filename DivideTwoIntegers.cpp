#include <iostream>

class Solution {
public:
    int divide(int dividend, int divisor) {
        if (divisor == 0)
            throw;
    
        int quotient = 0;
        
        if (dividend >= 0 && divisor > 0) {
            while (dividend >= divisor) {
                dividend -= divisor;
                quotient++;
            }
        } else if (dividend < 0 && divisor < 0) {
            while (dividend <= divisor) {
                dividend -= divisor;
                quotient++;
            }
        } else {
            bool isPositive = (divisor > 0);
            while ((dividend > 0) != isPositive) {
                dividend += divisor;
                quotient--;
            }
        }
        return quotient;
    }
};

int main()
{
    Solution solver;
    std::cout << "14 / 7: " << solver.divide(14, 7) << std::endl
              << "26 / 3: " << solver.divide(26, 3) << std::endl
              << "-14 / -7: " << solver.divide(-14, -7) << std::endl
              << "-26 / -3: " << solver.divide(-26, -3) << std::endl
              << "24 / -7: " << solver.divide(24, -7) << std::endl
              << "1 / -1: " << solver.divide(1, -1) << std::endl
              << "-24 / 7: " << solver.divide(-24, 7) << std::endl
              << "2147483647 / 1: " << solver.divide(2147483647, 1) << std::endl;
}
