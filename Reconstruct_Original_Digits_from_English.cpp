//
// Created by zhouyang on 2016/10/18.
//
#include <iostream>
#include <string>
#include <vector>

using namespace std;
/*
    The idea is:

    for zero, it's the only word has letter 'z',
    for two, it's the only word has letter 'w',
    ......
    so we only need to count the unique letter of each word, Coz the input is always valid.
 */
class Solution {
public:
    string originalDigits(string s) {
        int count[10] = {};
        for (auto ch:s) {
            switch (ch) {
                case 'z':
                    ++count[0];
                    break;
                case 'w':
                    ++count[2];
                    break;
                case 'u':
                    ++count[4];
                    break;
                case 'x':
                    ++count[6];
                    break;
                case 'g':
                    ++count[8];
                    break;
                case 'h':
                    ++count[3];
                    break;
                case 'f':
                    ++count[5];
                    break;
                case 's':
                    ++count[7];
                    break;
                case 'i':
                    ++count[9];
                    break;
                case 'o':
                    ++count[1];
                    break;
            }
        }
        // 0 -> z
        // 2 -> w
        // 4 -> u
        // 6 -> x
        // 8 -> g
        // 3 -> 'h' - 8
        // 5 -> 'f' - 4
        // 7 -> 's' - 6
        // 1 -> '0' - 0 - 2 - 4
        // 9 -> 'i' -8 - 6 -5 
        
        count[3] -= count[8];
        count[5] -= count[4];
        count[7] -= count[6];
        count[1] -= count[0] + count[2] + count[4];
        count[9] -= count[8] + count[6] + count[5];
        string result;
        for (int i = 0; i < 10; ++i) {
            for (int j = 0; j < count[i]; ++j) {
                result += to_string(i);
            }
        }
        return result;
    }

};

int main() {
    Solution s;
    string str;
    while (cin >> str) {
        cout << s.originalDigits(str) << endl;
    }

    return 0;
}
