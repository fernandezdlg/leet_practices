#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <bitset>

// Note: the brute force method yields stack overflow for large N (~80)
#define constN 16

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
            // 00..0: 00, 10, 01, 11 allowed:
            return 2*combinationsOpenBC(N - 2, false, false) + combinationsOpenBC(N - 2, false, true) + combinationsOpenBC(N - 2, true, true);
        }
    }

    bool acceptedBitset(bitset<constN> &a){
        // Rules:
        // the string has {1,0} elements  
        // the string has length N, for N positive even int
        // 1) The string cannot have any 111 subsequence
        // 2) The string can have one 11 sequence
        // 3) The string can have more than one 11 sequence only if the 11 sequences have a 00 in between.
        bool xx = false;
        bool xlast = false;
        for (size_t i = 0; i < constN; i++){
            if (a[i] == 0){
                if (xx) {
                    if (xlast){
                        xlast = false; // 11: 0
                    } else {
                        xx = false; // 11..0: 0
                    }
                } else if (xlast){
                    xlast = false; // 00..1: 0
                } else {
                    // continue; // 00: 0
                }
            } else { // if (a[i] == 1) {
                if (xx && xlast) { 
                    return false; // 11: 1 or 11..1: 1
                } else if (xlast) {
                    xx = true; // 00..1: 1
                } else {
                    xlast = true; // 00: 1
                }
            }
            // } else {
            //     cout << "Error: bitset has to be binary" << endl;
            //     return false;
            // }
        }    
        return true;    
    }

    size_t printAllConfigs(bool print = true){
        size_t bruteCount = 0;
        for (size_t i = 0; i < pow(2, constN); i++){
            bitset<constN> bs(i);
            if (acceptedBitset(bs)) {
                if (print) cout << bs << endl;
                bruteCount++;
            }    
        }
        return bruteCount;
    }

};


int main(){
    // Define size of chain (must be even positive int)
    Solution solution;

    size_t const testN = constN; // testN >= 2

    static_assert(testN % 2 == 0, "N must be even");
    static_assert(testN >= 2, "N >= 2");

    bool print = true; // print all configs if true
    if (print) cout << "All configs printed:" << endl;
    size_t bruteCount = solution.printAllConfigs(print);
    cout << "Brute force count: " << bruteCount << endl;

    size_t result = solution.combinationsOpenBC(testN, false, false);
    cout << "Result: " << result << endl;
    return 0;
}