#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <bitset>
#include <array>

// Note: the brute force method yields stack overflow for large N (~80)
#define constN 12

using namespace std;

class Solution
{
public:
    bool noOneRepeated(bitset<constN / 2> const& mask)
    {
        // check if there is no 1 repeated in the mask
        for (size_t i = 0; i < constN / 2 - 1; i++)
        {
            if (mask[i] == 1 && mask[i + 1] == 1)
            {
                return false;
            }
            else
            {
                continue;
            }
        }
        if (mask[0] == 1 && mask[constN / 2 - 1] == 1)
        {
            return false;
        }
        else
        {
            return true;
        }
    }


    size_t printAllMasksAndConfigs(bool print = true)
    {
        bitset<2> b(1);
        bitset<4> ad(3);

        size_t bruteCount = 0;
        for (size_t i = 0; i < pow(2, constN / 2); i++)
        {
            bitset<constN / 2> mask(i);  // mask , e.g. 0000 1111 0000 1111 1111 0000 1111
            if (noOneRepeated(mask))
            {
                if (print)
                {
                    cout << "Mask: " << mask << endl;
                    bitset<constN> bs2(0);
                    // base:
                    for (size_t j = 0; j < constN / 2; j++)
                    {
                        bs2[2 * j]     = b[0];
                        bs2[2 * j + 1] = b[1];
                    }

                    for (size_t j = 0; j < constN/2-1; j++)
                    {
                        if (mask[j] == 1)
                        {
                            bs2[2 * j]     = ad[0];
                            bs2[2 * j + 1] = ad[1];
                            bs2[2 * j + 2] = ad[2];
                            bs2[2 * j + 3] = ad[3];
                        }
                    }
                    size_t lastj = constN/2 - 1;
                    if (mask[lastj] == 1) {
                        bs2[2*lastj    ] = ad[0];
                        bs2[2*lastj + 1] = ad[1];
                        bs2[0]           = ad[2];
                        bs2[1]           = ad[3];
                    }
                    cout << "Config: " << bs2 << endl;
                }
                bruteCount++;
            }
        }
        return bruteCount;
    }

    size_t countPeriodicNoRepeatedOne(){
        const size_t N = constN/2;
        size_t a[N], b[N], c[N], d[N];
        a[0] = b[0] = c[0] = d[0] = 0; // undefined
        a[1] = b[1] = c[1] = 1; // 0..0, 0..1, 1..0, 1..1 and no repeated
        d[1] = 0; // 11 repeated
        cout << "{" << (4) << "," << (a[1] + b[1] + c[1]) << "},";
        for (size_t i = 2; i < N; i++) {
            a[i] = a[i-1] + b[i-1];
            b[i] = a[i-1];
            c[i] = c[i-1] + d[i-1];
            d[i] = c[i-1];
            cout << "{" << (2*(i+1)) << "," << (a[i] + b[i] + c[i]) << "},";
        }
        // cout << "{" << (2*(N-1)) << "," << (a[N] + b[N] + c[N]) << "},";
        return (a[N-1] + b[N-1] + c[N-1]);
    }

    size_t printAllMasks(bool print = true)
    {
        size_t bruteCount = 0;
        for (size_t i = 0; i < pow(2, constN / 2); i++)
        {
            bitset<constN / 2> mask(i);  // mask , e.g. 0000 1111 0000 1111 1111 0000 1111
            if (noOneRepeated(mask))
            {
                if (print)
                {
                    cout << mask << endl;
                }
                bruteCount++;
            }
        }
        return bruteCount;
    }

    size_t printAllConfigs(bool print = true)
    {
        bitset<2> b(1);
        bitset<4> ad(3);

        size_t bruteCount = 0;
        for (size_t i = 0; i < pow(2, constN / 2); i++)
        {
            bitset<constN / 2> mask(i);  // mask , e.g. 0000 1111 0000 1111 1111 0000 1111
            if (noOneRepeated(mask))
            {
                if (print)
                {
                    bitset<constN> bs2(0);
                    // base:
                    for (size_t j = 0; j < constN / 2; j++)
                    {
                        bs2[2 * j]     = b[0];
                        bs2[2 * j + 1] = b[1];
                    }

                    for (size_t j = 0; j < constN/2-1; j++)
                    {
                        if (mask[j] == 1)
                        {
                            bs2[2 * j]     = ad[0];
                            bs2[2 * j + 1] = ad[1];
                            bs2[2 * j + 2] = ad[2];
                            bs2[2 * j + 3] = ad[3];
                        }
                    }
                    size_t lastj = constN/2 - 1;
                    if (mask[lastj] == 1) {
                        bs2[2*lastj    ] = ad[0];
                        bs2[2*lastj + 1] = ad[1];
                        bs2[0]           = ad[2];
                        bs2[1]           = ad[3];
                    }
                    cout << "Config: " << bs2 << endl;
                }
                bruteCount++;
            }
        }
        return bruteCount;
    }
};


int main()
{
    // Define size of chain (must be even positive int)
    Solution solution;

    size_t const testN = constN;  // testN >= 2

    static_assert(testN % 2 == 0, "N must be even");
    static_assert(testN >= 2, "N >= 2");

    bool print = true;  // print all configs if true
    size_t bruteCount = 0;

    // Tests for noOneRepeated
    cout << "Tests for noOneRepeated:" << endl;
    bitset<testN/2> mask(0);
    cout << "mask: " << mask << endl;
    cout << "noOneRepeated: " << solution.noOneRepeated(mask) << endl;
    mask = bitset<testN/2>(3);
    cout << "mask: " << mask << endl;
    cout << "noOneRepeated: " << solution.noOneRepeated(mask) << endl;
    mask = bitset<testN/2>(5);
    cout << "mask: " << mask << endl;
    cout << "noOneRepeated: " << solution.noOneRepeated(mask) << endl << endl;

    // Tests for printAllMasksAndConfigs
    cout << "Tests for printAllMasksAndConfigs:" << endl;
    if (print)
        cout << "All masks and configs printed:" << endl;
    bruteCount = solution.printAllMasksAndConfigs(print);
    cout << "Brute force count: " << bruteCount << endl << endl;

    // Tests for countPeriodicNoRepeatedOne
    cout << "Tests for countPeriodicNoRepeatedOne:" << endl;
    auto result = solution.countPeriodicNoRepeatedOne();
    cout << "\nResult: " << result << endl << endl;

    // Tests for printAllMasks
    cout << "Tests for printAllMasks:" << endl;
    if (print)
        cout << "All masks printed:" << endl;
    bruteCount = solution.printAllMasks(print);
    cout << "Brute force count: " << bruteCount << endl << endl;

    // Tests for printAllConfigs
    cout << "Tests for printAllConfigs:" << endl;
    if (print) cout << "All configs printed:" << endl;
    bruteCount = solution.printAllConfigs();
    cout << "Brute force count: " << bruteCount << endl << endl;

    return 0;
}