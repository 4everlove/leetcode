#include <iostream>
using namespace std;

class Solution {
public:
    int lengthOfLastWord(const char *s) {
        int count = 0, countLastWord = 0;
        const char *space = s, *advance = s;
        
        if (s == NULL)
            return 0;
        
        while (*space) {
            if (*advance != ' ' && *advance != '\0') {
                advance++;
                count++;
//                cout << "current count: " << count
//                     << ", next character: " << *advance << std::endl;
            } else {
                countLastWord = count == 0 ? countLastWord : count;
                count = 0;
                space = advance;
                advance++;
//                cout << "Space found: " << countLastWord
//                     << ", current character: " << *space << std::endl;
            }
        }
        
        return countLastWord;
    }
};

int main() {
    Solution solver;
    cout << "Empty string: " << solver.lengthOfLastWord("") << std::endl
         << "Hello World: " << solver.lengthOfLastWord("Hello World") << std::endl
         << "all small case: " << solver.lengthOfLastWord("all small case") << std::endl
         << "    leading space: " << solver.lengthOfLastWord("    leading space") << std::endl
         << "trailing space    : " << solver.lengthOfLastWord("trailing space    ") << std::endl
         << "space in    sentence  : " << solver.lengthOfLastWord("space in    sentence  ") << std::endl;
    return 0;
}
