#if PARALLEL
#include <execution>
#define SEQ std::execution::seq,
#define PAR std::execution::par,
#else
#define SEQ
#define PAR
#endif

#include <vector>
#include <iostream>
#include <numeric>


using namespace std;



class Solution
{
public:
    int numberOfBeautifulIntegers(int low, int high, int k)
    {
        // Beautifulness conditions:
        // Count of EVEN digits == Count of ODD digits.
        // Number divisible by k.

        // if (k == 0)
        //     runtime_error("k is not positive integer");

        auto checkIfSumDigits = [](int num)
        {
            int evenCount = 0;
            int oddCount  = 0;
            int digit;

            while (num != 0)
            {
                digit = num % 10;  // Get the last digit

                if (digit % 2 == 0)
                {
                    evenCount++;
                }
                else
                {
                    oddCount++;
                }

                num /= 10;  // Remove the last digit
            }
            return (evenCount == oddCount);
        };

        auto selectIfDivisible = [](int k) -> std::function<bool(int)>
        {
            // int sum;
            // int a, b;

            // int sumodd;
            // int sumeven;

            switch (k)
            {
                case 1:
                    return [](int num) -> bool { return true; };
                case 2:
                    return [](int num) -> bool { return (!(num & 1)); };
                case 3:
                    return [](int num) -> bool
                    {
                        int sum;
                        while (num / 10 != 0)
                        {
                            sum = 0;
                            while (num != 0)
                            {
                                sum += num % 10;  // Add the last digit to the sum
                                num /= 10;        // Remove the last digit
                            }
                            num = sum;
                        }
                        return (num % 3 == 0);
                    };
                case 4:
                    return [](int num) -> bool { return ((num % 100) % 4 == 0); };
                case 5:
                    return [](int num) -> bool
                    {
                        num = num % 10;
                        return (num == 5 || num == 0);
                    };
                case 6:
                    return [](int num) -> bool
                    {
                        int sum;
                        if (!(num & 1))
                        {
                            while (num / 10 != 0)
                            {
                                sum = 0;
                                while (num != 0)
                                {
                                    sum += num % 10;  // Add the last digit to the sum
                                    num /= 10;        // Remove the last digit
                                }
                                num = sum;
                            }
                            return (num % 3 == 0);
                        }
                        return false;
                    };
                case 7:
                    return [](int num) -> bool
                    {
                        int a, b;
                        while (num / 64 != 0)
                        {
                            a   = num / 10;
                            b   = num % 10;
                            num = abs(a - 2 * b);
                        }
                        return (num % 7 == 0);
                    };
                case 8:
                    return [](int num) -> bool { return ((num % 1000) % 8 == 0); };
                case 9:
                    return [](int num) -> bool
                    {
                        int sum;
                        while (num / 10 != 0)
                        {
                            sum = 0;
                            while (num != 0)
                            {
                                sum += num % 10;  // Add the last digit to the sum
                                num /= 10;        // Remove the last digit
                            }
                            num = sum;
                        }
                        return (num % 9 == 0);
                    };
                case 10:
                    return [](int num) -> bool { return (num % 10 == 0); };
                case 11:
                    return [](int num) -> bool
                    {
                        int sumodd, sumeven;
                        // sum odd
                        while (num / 10 != 0)
                        {
                            sumodd  = 0;
                            sumeven = 0;
                            while (num != 0)
                            {
                                sumodd += num % 10;  // Add the last digit to the sumodd
                                num /= 10;           // Remove the last digit
                                sumeven += num % 10;
                                num /= 10;
                            }
                            num = abs(sumodd - sumeven);
                        }
                        return (num == 0);
                    };
                case 12:
                    return [](int num) -> bool
                    {
                        int sum;
                        if ((num % 100) % 4 == 0)
                        {
                            while (num / 10 != 0)
                            {
                                sum = 0;
                                while (num != 0)
                                {
                                    sum += num % 10;  // Add the last digit to the sum
                                    num /= 10;        // Remove the last digit
                                }
                                num = sum;
                            }
                            return (num % 3 == 0);
                        }
                        return false;
                    };
                case 13:
                    return [](int num) -> bool
                    {
                        int a, b;

                        while (num / 128 != 0)
                        {
                            a   = num / 10;
                            b   = num % 10;
                            num = abs(a - 9 * b);
                        }
                        return (num % 13 == 0);
                    };
                case 14:
                    return [](int num) -> bool
                    {
                        int a, b;

                        if (!(num & 1))
                        {
                            while (num / 64 != 0)
                            {
                                a   = num / 10;
                                b   = num % 10;
                                num = abs(a - 2 * b);
                            }
                            return (num % 7 == 0);
                        }
                        return false;
                    };
                case 15:
                    return [](int num) -> bool
                    {
                        int sum;
                        if ((num % 10) == 5 || (num % 10) == 0)
                        {
                            while (num / 10 != 0)
                            {
                                sum = 0;
                                while (num != 0)
                                {
                                    sum += num % 10;  // Add the last digit to the sum
                                    num /= 10;        // Remove the last digit
                                }
                                num = sum;
                            }
                            return (num % 3 == 0);
                        }
                        return false;
                    };
                case 16:
                    return [](int num) -> bool { return ((num % 10000) % 16 == 0); };
                case 17:
                    return [](int num) -> bool

                    {
                        int a, b;
                        while (num / 128 != 0)
                        {
                            a   = num / 10;
                            b   = num % 10;
                            num = abs(a - 5 * b);
                        }
                        return (num % 17 == 0);
                    };
                case 18:
                    return [](int num) -> bool
                    {
                        int sum;
                        if (!(num & 1))
                        {
                            while (num / 10 != 0)
                            {
                                sum = 0;
                                while (num != 0)
                                {
                                    sum += num % 10;  // Add the last digit to the sum
                                    num /= 10;        // Remove the last digit
                                }
                                num = sum;
                            }
                            return (num % 9 == 0);
                        }
                        return false;
                    };
                case 19:
                    return [](int num) -> bool
                    {
                        int a, b;
                        while (num / 256 != 0)
                        {
                            a   = num / 10;
                            b   = num % 10;
                            num = abs(a - 17 * b);
                        }
                        return (num % 19 == 0);
                    };
                case 20:
                    return [](int num) -> bool
                    {
                        if ((num % 100) % 4 == 0)
                        {
                            num = num % 10;
                            return (num == 5 || num == 0);
                        }
                        return false;
                    };
                default:
                    return [](int num) -> bool { return false; }; // Default case
            }
        };

        // Constraints:
        // low , high <= 10^9 => using ints is fine (-2.1 B -> 2.1 B)
        // k ∈ [0,20], ∈ \mathbb{Z}

        // ranges::for_each(low, high, checkIfDivisible(self));
        int  result           = 0;
        bool noBreak          = true;
        auto checkIfDivisible = selectIfDivisible(k);
        high = min(high, 100000000); // xD
        for (size_t i = low; i <= high; i++)
        {
            if (noBreak)
            {
                if (checkIfDivisible(i))
                {
                    if (checkIfSumDigits(i))
                    {
                        result++;
                    }
                    noBreak = false;
                    i += k - 1;
                }
            }
            else
            {
                // if (checkIfDivisible(i))
                // {
                    if (checkIfSumDigits(i))
                    {
                        result++;
                    }
                    i += k - 1;
                // }
            }
        }
        return result;

        // return checkIfDivisible(
        //     low);  // Return the NUMBER of beautiful INTEGERS in the range [LOW, HIGH]
    }
};

int main()
{
    Solution solution;

    vector<int> test = { 1, 10, 1};  // low, high, k

    int result = solution.numberOfBeautifulIntegers(test[0], test[1], test[2]);

    cout << result << endl;
    return 0;
}
