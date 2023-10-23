#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <bitset>


using namespace std;


class Solution
{
public:
    size_t combinationsOpenBC(size_t N, bool xx, bool xlast) {
        // Rules:
        // the string has {1,0} elements
        // the string has length N, for N positive even int
        // 1) The string cannot have any 111 subsequence
        // 2) The string can have one 11 sequence
        // 3) The string can have more than one 11 sequence only if the 11 sequences have a 00 in between.

        if (N == 2)
        {   
            if (xx) {
                if (xlast){
                    return 2; // 11: 00, 01
                } else {
                    return 3; // 11..0: 01, 10, 00
                }
            } else if (xlast){
                return 3; // 00..1: 00, 01, 10
            } else {
                return 4; // 00 : 00, 01, 10, 11
            }
        }


        if (xx) {
            if (xlast) {
                // 11: 00, 01 allowed:
                return combinationsOpenBC(N - 2, false, false) + combinationsOpenBC(N - 2, true, true);
            } else {
                // 11..0 : 00, 01, 10 allowed:
                return combinationsOpenBC(N - 2, false, false) + combinationsOpenBC(N - 2, false, true) + combinationsOpenBC(N - 2, true, false);
            }
        } else if (xlast) {
            // 00..1: 10, 00, 01 allowed:
            return combinationsOpenBC(N - 2, true, false) + combinationsOpenBC(N - 2, false, false) + combinationsOpenBC(N - 2, false, true);
        } else {
            // 00..0: 00, 01, 10, 11 allowed:
            return combinationsOpenBC(N - 2, false, false) + combinationsOpenBC(N - 2, false, true) + combinationsOpenBC(N - 2, true, true);
        }
    }
};


int main(){
    // Define size of chain (must be even positive int)

    Solution solution;

    size_t const testN = 4; // testN >= 2

    static_assert(testN % 2 == 0, "N must be even");
    static_assert(testN >= 2, "N >= 2");
    int result = solution.combinationsOpenBC(testN, false, false);

    cout << result << endl;
    return 0;
}