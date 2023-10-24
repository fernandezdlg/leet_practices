#include <iostream>

using namespace std;

class Solution
{
public:
    size_t combinationsOpenBC(size_t const N, bool xx, bool xlast) {
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
            // 00..0: 00, 10, 01, 11 allowed:
            return 2*combinationsOpenBC(N - 2, false, false) + combinationsOpenBC(N - 2, false, true) + combinationsOpenBC(N - 2, true, true);
        }
    }

};


int main(){
    // Define size of chain (must be even positive int)
    Solution solution;
    cout << "{ ";
    for (size_t i = 2; i <= 40; i+=2)
    {
        size_t result = solution.combinationsOpenBC(i, false, false);
        // cout << result << ", ";
        cout << "{ " << i << ", " << result << " }, ";
    }
    cout << "} ";

    return 0;
}